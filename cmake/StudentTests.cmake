# Тесты студента: файлы tests/student/*_test.cpp задачи собираются в цель ${TASK}-tests-student
# (Google Test) и, если есть тесты на Catch2, в цель ${TASK}-tests-student-catch2.
# Вызов add_student_tests создаёт CMakeLists.txt лабораторной (scripts/assemble_labs.py)
# после add_subdirectory задачи с папкой include/: код задачи уже собран в библиотеку ${TASK}-lib.
include_guard()

function(add_student_tests TASK TASK_DIR)
    # CONFIGURE_DEPENDS: новый файл с тестами подхватывается при сборке без ручного cmake --preset
    file(GLOB STUDENT_TESTS CONFIGURE_DEPENDS ${TASK_DIR}/tests/student/*_test.cpp)
    if(NOT STUDENT_TESTS OR NOT TARGET ${TASK}-lib)
        return()
    endif()
    # Фреймворк выбирается по каждому файлу: #include <catch2/…> — Catch2, иначе Google Test.
    # Файлы на разных фреймворках собираются в разные программы: у каждого свой main
    set(GTEST_FILES)
    set(CATCH2_FILES)
    foreach(_file IN LISTS STUDENT_TESTS)
        file(STRINGS ${_file} _catch2_include REGEX "^[ \t]*#[ \t]*include[ \t]*<catch2/" LIMIT_COUNT 1)
        if(_catch2_include)
            list(APPEND CATCH2_FILES ${_file})
        else()
            list(APPEND GTEST_FILES ${_file})
        endif()
    endforeach()
    if(GTEST_FILES)
        _add_student_test_program(${TASK} ${TASK}-tests-student GTest::gtest_main "${GTEST_FILES}")
        # TIMEOUT: тест с зациклившейся функцией останавливается через 10 секунд
        gtest_discover_tests(${TASK}-tests-student TEST_PREFIX "${TASK}.student." PROPERTIES TIMEOUT 10)
    endif()
    if(CATCH2_FILES)
        _add_student_test_program(${TASK} ${TASK}-tests-student-catch2 Catch2::Catch2WithMain "${CATCH2_FILES}")
        catch_discover_tests(${TASK}-tests-student-catch2 TEST_PREFIX "${TASK}.student." PROPERTIES TIMEOUT 10)
    endif()
endfunction()

# Программа с тестами студента: код задачи ${TASK}-lib + библиотека фреймворка с готовым main
function(_add_student_test_program TASK TARGET FRAMEWORK FILES)
    add_executable(${TARGET} ${FILES})
    # Решение-модуль (cmake/TaskLibrary.cmake): тесты импортируют его, CMake должен искать в них import
    get_target_property(_definitions ${TASK}-lib INTERFACE_COMPILE_DEFINITIONS)
    if(_definitions AND "CPPLABS_USE_MODULES" IN_LIST _definitions)
        set_target_properties(${TARGET} PROPERTIES CXX_SCAN_FOR_MODULES ON)
    endif()
    target_link_libraries(${TARGET} PRIVATE ${TASK}-lib ${FRAMEWORK})
    # В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
    set_target_properties(${TARGET} PROPERTIES CXX_CLANG_TIDY "")
endfunction()
