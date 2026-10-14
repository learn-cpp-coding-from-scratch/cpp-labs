cmake_minimum_required(VERSION 3.24)   # 3.24: FIND_PACKAGE_ARGS в cmake/Dependencies.cmake
project(cpp_labs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)                 # -std=c++20, а не -std=gnu++20
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)         # compile_commands.json для clangd в VS Code

# Программы и тесты всех лабораторных — в одной папке build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Google Test подключается до clang-tidy: код библиотеки проверять не нужно
include(${CMAKE_SOURCE_DIR}/cmake/Dependencies.cmake)
# add_student_tests: тесты студента tests/student/ — вызывается в CMakeLists.txt лабораторных
include(${CMAKE_SOURCE_DIR}/cmake/StudentTests.cmake)
# add_task_library: библиотека с кодом задачи — заголовок и .cpp или модуль C++20 (по выбору студента)
include(${CMAKE_SOURCE_DIR}/cmake/TaskLibrary.cmake)

# Предупреждения компилятора
if(MSVC)
    add_compile_options(/W4 /utf-8)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# clang-tidy при каждой сборке; конфиг .clang-tidy — в корне репозитория
find_program(CLANG_TIDY_EXE NAMES clang-tidy)
if(CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE})
else()
    message(WARNING "clang-tidy не найден — сборка без проверки стиля.")
endif()

# Общая библиотека cpplabs (common/) подключается ко всем программам и тестам лабораторных;
# link_libraries действует на цели, созданные после этой строки
add_subdirectory(common)
link_libraries(cpplabs)
# Компоновщик macOS (Xcode 15+) предупреждает, что cpplabs подключена дважды: к программе
# напрямую и через библиотеку задачи. Повтор безвреден — предупреждение отключено
include(CheckLinkerFlag)
check_linker_flag(CXX "LINKER:-no_warn_duplicate_libraries" HAS_NO_WARN_DUPLICATE_LIBRARIES)
if(HAS_NO_WARN_DUPLICATE_LIBRARIES)
    add_link_options(LINKER:-no_warn_duplicate_libraries)
endif()

# Все лабораторные: папки lab-*, в которых есть CMakeLists.txt
file(GLOB _LAB_CMAKELISTS RELATIVE ${CMAKE_SOURCE_DIR} "lab-*/CMakeLists.txt")
list(SORT _LAB_CMAKELISTS)
foreach(_cmake IN LISTS _LAB_CMAKELISTS)
    get_filename_component(_lab_dir ${_cmake} DIRECTORY)
    message(STATUS "Лабораторная: ${_lab_dir}")
    add_subdirectory(${_lab_dir})
endforeach()

# Форматирование всего кода: cmake --build build --target format
find_program(CLANG_FORMAT_EXE NAMES clang-format)
if(CLANG_FORMAT_EXE)
    file(GLOB_RECURSE ALL_CXX_FILES
        ${CMAKE_SOURCE_DIR}/common/*.cpp
        ${CMAKE_SOURCE_DIR}/common/*.hpp
        ${CMAKE_SOURCE_DIR}/lab-*/*.cpp
        ${CMAKE_SOURCE_DIR}/lab-*/*.hpp
        ${CMAKE_SOURCE_DIR}/lab-*/*.cppm
    )
    add_custom_target(format
        COMMAND ${CLANG_FORMAT_EXE} -i ${ALL_CXX_FILES}
        COMMENT "Форматирование кода clang-format..."
    )
endif()
