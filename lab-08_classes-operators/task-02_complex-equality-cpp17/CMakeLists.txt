# Задача complex-equality-cpp17
# TASK — префикс имён целей (например, lab-08-task-02), его задаёт CMakeLists.txt лабораторной
# Задача собирается по стандарту C++17 (-std=c++17): так сравнение на равенство писали до C++20

# Код задачи без main — библиотека для программы и для тестов
add_library(${TASK}-lib src/complex_number.cpp)
target_include_directories(${TASK}-lib PUBLIC include)

# Программа
add_executable(${TASK}_complex-equality-cpp17 src/complex_equality_cpp17_main.cpp)
target_link_libraries(${TASK}_complex-equality-cpp17 PRIVATE ${TASK}-lib)

# Открытые тесты
add_executable(${TASK}-tests tests/open/complex_equality_cpp17_test.cpp)
target_link_libraries(${TASK}-tests PRIVATE ${TASK}-lib GTest::gtest_main)
# В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
set_target_properties(${TASK}-tests PROPERTIES CXX_CLANG_TIDY "")
# TIMEOUT: тест с зациклившейся функцией останавливается через 10 секунд, а не через 25 минут
gtest_discover_tests(${TASK}-tests TEST_PREFIX "${TASK}.open." PROPERTIES TIMEOUT 10)

# Стандарт C++17 для всех целей задачи (в корневом CMakeLists.txt — C++20)
set_target_properties(${TASK}-lib ${TASK}_complex-equality-cpp17 ${TASK}-tests PROPERTIES CXX_STANDARD 17)
