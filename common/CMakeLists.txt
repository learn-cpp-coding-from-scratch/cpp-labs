# Общая библиотека cpplabs: функции, которыми пользуются задачи всех лабораторных.
# Заголовки — include/cpplabs/<модуль>.hpp (подключаются как <cpplabs/<модуль>.hpp>),
# реализация — src/<модуль>.cpp, тесты — tests/<модуль>_test.cpp.
# Файлы собираются по маске: новый модуль добавляется без правки этого файла.
# CONFIGURE_DEPENDS: при сборке CMake заново проверяет маски и замечает новые файлы.
file(GLOB_RECURSE CPPLABS_HEADERS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/include/cpplabs/*.hpp)
file(GLOB_RECURSE CPPLABS_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(cpplabs STATIC ${CPPLABS_SOURCES} ${CPPLABS_HEADERS})
target_include_directories(cpplabs PUBLIC include)

# Тесты общей библиотеки: после её изменения запускаются вместе с тестами всех лабораторных
file(GLOB_RECURSE CPPLABS_TESTS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/*_test.cpp)
add_executable(cpplabs-tests ${CPPLABS_TESTS})
target_link_libraries(cpplabs-tests PRIVATE cpplabs GTest::gtest_main)
# В тестах числа-ожидания — не «магические»: clang-tidy для тестов отключён
set_target_properties(cpplabs-tests PROPERTIES CXX_CLANG_TIDY "")
gtest_discover_tests(cpplabs-tests TEST_PREFIX "cpplabs.")
