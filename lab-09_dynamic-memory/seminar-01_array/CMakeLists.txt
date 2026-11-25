# Задача array
# TASK — префикс имён целей (например, lab-09-seminar-01), его задаёт CMakeLists.txt лабораторной

# Код задачи — шаблоны классов, они целиком в заголовочных файлах: библиотека без исходников
# (INTERFACE) только передаёт программе и тестам путь к include/
add_library(${TASK}-lib INTERFACE)
target_include_directories(${TASK}-lib INTERFACE include)

# Программа
add_executable(${TASK}_array src/array_main.cpp)
target_link_libraries(${TASK}_array PRIVATE ${TASK}-lib)

# Открытые тесты
add_executable(${TASK}-tests
    tests/open/array_test.cpp
    tests/open/array_service_test.cpp
)
target_link_libraries(${TASK}-tests PRIVATE ${TASK}-lib GTest::gtest_main)
# В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
set_target_properties(${TASK}-tests PROPERTIES CXX_CLANG_TIDY "")
# TIMEOUT: тест с зациклившейся функцией останавливается через 10 секунд, а не через 25 минут
gtest_discover_tests(${TASK}-tests TEST_PREFIX "${TASK}.open." PROPERTIES TIMEOUT 10)
