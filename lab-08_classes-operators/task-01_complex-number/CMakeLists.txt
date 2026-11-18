# Задача complex-number
# TASK — префикс имён целей (например, lab-08-task-01), его задаёт CMakeLists.txt лабораторной

# Код задачи без main — библиотека для программы и для тестов
add_library(${TASK}-lib
    src/complex_number.cpp
    src/mandelbrot.cpp
    src/program.cpp
)
target_include_directories(${TASK}-lib PUBLIC include)

# Программа
add_executable(${TASK}_complex-number src/complex_number_main.cpp)
target_link_libraries(${TASK}_complex-number PRIVATE ${TASK}-lib)

# Открытые тесты
add_executable(${TASK}-tests
    tests/open/complex_number_test.cpp
    tests/open/mandelbrot_test.cpp
    tests/open/program_test.cpp
)
target_link_libraries(${TASK}-tests PRIVATE ${TASK}-lib GTest::gtest_main)
# В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
set_target_properties(${TASK}-tests PROPERTIES CXX_CLANG_TIDY "")
# TIMEOUT: тест с зациклившейся функцией останавливается через 10 секунд, а не через 25 минут
gtest_discover_tests(${TASK}-tests TEST_PREFIX "${TASK}.open." PROPERTIES TIMEOUT 10)
