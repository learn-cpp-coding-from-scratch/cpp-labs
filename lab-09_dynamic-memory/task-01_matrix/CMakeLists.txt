# Задача matrix
# TASK — префикс имён целей (например, lab-09-task-01), его задаёт CMakeLists.txt лабораторной

# Шаблоны Matrix и MatrixService целиком в заголовочных файлах; в библиотеке — только
# обычные функции MatrixService для Matrix<double>
add_library(${TASK}-lib src/matrix_service.cpp)
target_include_directories(${TASK}-lib PUBLIC include)

# Программа
add_executable(${TASK}_matrix src/matrix_main.cpp)
target_link_libraries(${TASK}_matrix PRIVATE ${TASK}-lib)

# Открытые тесты
add_executable(${TASK}-tests
    tests/open/matrix_test.cpp
    tests/open/matrix_service_test.cpp
)
target_link_libraries(${TASK}-tests PRIVATE ${TASK}-lib GTest::gtest_main)
# В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
set_target_properties(${TASK}-tests PROPERTIES CXX_CLANG_TIDY "")
# TIMEOUT: тест с зациклившейся функцией останавливается через 10 секунд, а не через 25 минут
gtest_discover_tests(${TASK}-tests TEST_PREFIX "${TASK}.open." PROPERTIES TIMEOUT 10)
