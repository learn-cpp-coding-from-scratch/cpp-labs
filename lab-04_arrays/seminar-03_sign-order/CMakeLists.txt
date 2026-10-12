# Задача sign-order
# TASK — префикс имён целей (например, lab-03-task-02), его задаёт CMakeLists.txt лабораторной

# Код задачи без main — библиотека для программы и для тестов
add_library(${TASK}-lib src/sign_order.cpp)
target_include_directories(${TASK}-lib PUBLIC include)

# Программа
add_executable(${TASK}_sign-order src/sign_order_main.cpp)
target_link_libraries(${TASK}_sign-order PRIVATE ${TASK}-lib)

# Открытые тесты
add_executable(${TASK}-tests tests/open/sign_order_test.cpp)
target_link_libraries(${TASK}-tests PRIVATE ${TASK}-lib GTest::gtest_main)
# В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
set_target_properties(${TASK}-tests PROPERTIES CXX_CLANG_TIDY "")
# TIMEOUT: тест с зациклившейся функцией останавливается через 10 секунд, а не через 25 минут
gtest_discover_tests(${TASK}-tests TEST_PREFIX "${TASK}.open." PROPERTIES TIMEOUT 10)
