# Задача country-populations
# TASK — префикс имён целей (например, lab-03-task-02), его задаёт CMakeLists.txt лабораторной

# Код задачи без main — библиотека для программы и для тестов
add_library(${TASK}-lib
    src/file_reader.cpp
    src/country.cpp
    src/world_population.cpp
    src/country_feature.cpp
    src/world_country.cpp
    src/world_region_population.cpp
    src/program.cpp
)
target_include_directories(${TASK}-lib PUBLIC include)

# Программа
add_executable(${TASK}_country-populations src/country_populations_main.cpp)
target_link_libraries(${TASK}_country-populations PRIVATE ${TASK}-lib)
# Программа — в build/bin/${TASK}/, рядом с ней — копия папки data/ задачи (cmake/TaskData.cmake)
add_task_data(${TASK}_country-populations)

# Открытые тесты
add_executable(${TASK}-tests
    tests/open/file_reader_test.cpp
    tests/open/country_test.cpp
    tests/open/world_population_test.cpp
    tests/open/country_feature_test.cpp
    tests/open/world_country_test.cpp
    tests/open/world_region_population_test.cpp
    tests/open/program_test.cpp
)
target_link_libraries(${TASK}-tests PRIVATE ${TASK}-lib GTest::gtest_main)
# Тесты читают файлы данных задачи прямо из её папки data/
target_compile_definitions(${TASK}-tests PRIVATE TASK_DATA_DIRECTORY="${CMAKE_CURRENT_SOURCE_DIR}/data")
# В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
set_target_properties(${TASK}-tests PROPERTIES CXX_CLANG_TIDY "")
# TIMEOUT: тест с зациклившейся функцией останавливается через 10 секунд, а не через 25 минут
gtest_discover_tests(${TASK}-tests TEST_PREFIX "${TASK}.open." PROPERTIES TIMEOUT 10)
