# Задача missing-digit
# TASK — префикс имён целей (например, lab-03-task-02), его задаёт CMakeLists.txt лабораторной

# Код задачи без main — библиотека для программы и для тестов:
# include/ и src/missing_digit.cpp или модуль src/missing_digit.cppm (cmake/TaskLibrary.cmake)
add_task_library(missing_digit)

# Программа
add_executable(${TASK}_missing-digit src/missing_digit_main.cpp)
target_link_libraries(${TASK}_missing-digit PRIVATE ${TASK}-lib)

# Открытые тесты
add_executable(${TASK}-tests tests/open/missing_digit_test.cpp)
target_link_libraries(${TASK}-tests PRIVATE ${TASK}-lib GTest::gtest_main)
# В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
set_target_properties(${TASK}-tests PROPERTIES CXX_CLANG_TIDY "")
# TIMEOUT: тест с зациклившейся функцией останавливается через 10 секунд, а не через 25 минут
gtest_discover_tests(${TASK}-tests TEST_PREFIX "${TASK}.open." PROPERTIES TIMEOUT 10)
