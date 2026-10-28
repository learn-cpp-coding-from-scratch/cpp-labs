# Задача sorting-algorithms
# TASK — префикс имён целей (например, lab-03-task-02), его задаёт CMakeLists.txt лабораторной

# Код задачи без main — библиотека для программы и для тестов
add_library(${TASK}-lib
    src/sorting_algorithms.cpp
    src/data_io.cpp
    src/data_generation.cpp
    src/sorting_experiment.cpp
)
target_include_directories(${TASK}-lib PUBLIC include)

# Программа
add_executable(${TASK}_sorting-algorithms src/sorting_algorithms_main.cpp)
target_link_libraries(${TASK}_sorting-algorithms PRIVATE ${TASK}-lib)
# Программа — в build/bin/${TASK}/, рядом с ней — копия папки data/ задачи (cmake/TaskData.cmake)
add_task_data(${TASK}_sorting-algorithms)

# Открытые тесты
add_executable(${TASK}-tests
    tests/open/sorting_algorithms_test.cpp
    tests/open/data_io_test.cpp
    tests/open/data_generation_test.cpp
    tests/open/sorting_experiment_test.cpp
)
target_link_libraries(${TASK}-tests PRIVATE ${TASK}-lib GTest::gtest_main)
# В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
set_target_properties(${TASK}-tests PROPERTIES CXX_CLANG_TIDY "")
# TIMEOUT: тест с зациклившейся функцией останавливается через 10 секунд, а не через 25 минут
gtest_discover_tests(${TASK}-tests TEST_PREFIX "${TASK}.open." PROPERTIES TIMEOUT 10)
