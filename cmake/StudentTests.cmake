# Тесты студента: файлы tests/student/*_test.cpp задачи собираются в цель ${TASK}-tests-student.
# Вызов add_student_tests создаёт CMakeLists.txt лабораторной (scripts/assemble_labs.py)
# после add_subdirectory задачи с папкой include/: код задачи уже собран в библиотеку ${TASK}-lib.
include_guard()

function(add_student_tests TASK TASK_DIR)
    # CONFIGURE_DEPENDS: новый файл с тестами подхватывается при сборке без ручного cmake --preset
    file(GLOB STUDENT_TESTS CONFIGURE_DEPENDS ${TASK_DIR}/tests/student/*_test.cpp)
    if(NOT STUDENT_TESTS OR NOT TARGET ${TASK}-lib)
        return()
    endif()
    add_executable(${TASK}-tests-student ${STUDENT_TESTS})
    # Решение-модуль (cmake/TaskLibrary.cmake): тесты импортируют его, CMake должен искать в них import
    get_target_property(_definitions ${TASK}-lib INTERFACE_COMPILE_DEFINITIONS)
    if(_definitions AND "CPPLABS_USE_MODULES" IN_LIST _definitions)
        set_target_properties(${TASK}-tests-student PROPERTIES CXX_SCAN_FOR_MODULES ON)
    endif()
    target_link_libraries(${TASK}-tests-student PRIVATE ${TASK}-lib GTest::gtest_main)
    # В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
    set_target_properties(${TASK}-tests-student PROPERTIES CXX_CLANG_TIDY "")
    # TIMEOUT: тест с зациклившейся функцией останавливается через 10 секунд
    gtest_discover_tests(${TASK}-tests-student TEST_PREFIX "${TASK}.student." PROPERTIES TIMEOUT 10)
endfunction()
