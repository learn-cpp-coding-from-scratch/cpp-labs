# Библиотека с кодом задачи: add_task_library(<имя>) создаёт цель ${TASK}-lib — код задачи без main
# для программы и тестов. Вызывается в CMakeLists.txt задачи; TASK задаёт CMakeLists.txt лабораторной.
#
# Решение можно оформить двумя способами (по выбору студента, тема 1.5):
#   - заголовочный файл include/<имя>.hpp и файл реализации src/<имя>.cpp — по умолчанию;
#   - модуль C++20 src/<имя>.cppm — заготовка src/<имя>.cppm.example: переименуйте её в <имя>.cppm,
#     а include/<имя>.hpp и src/<имя>.cpp удалите.
# Вариант выбирается по наличию файла src/<имя>.cppm. Для модуля задаётся макрос CPPLABS_USE_MODULES:
# по нему программа и тесты выбирают import <имя>; или #include "<имя>.hpp".
include_guard()

function(add_task_library NAME)
    set(_module ${CMAKE_CURRENT_SOURCE_DIR}/src/${NAME}.cppm)
    if(NOT EXISTS ${_module})
        add_library(${TASK}-lib src/${NAME}.cpp)
        target_include_directories(${TASK}-lib PUBLIC include)
        return()
    endif()

    # Ограничения инструментов — см. учебник, тема 1.5.2, Таблица 1.21
    if(CMAKE_VERSION VERSION_LESS 3.28)
        message(FATAL_ERROR "${TASK}: для модулей C++20 нужен CMake 3.28 или новее (сейчас ${CMAKE_VERSION}). "
            "Обновите CMake или верните решение в include/${NAME}.hpp и src/${NAME}.cpp.")
    endif()
    if(NOT CMAKE_GENERATOR MATCHES "Ninja|Visual Studio")
        message(FATAL_ERROR "${TASK}: модули C++20 собираются только генератором Ninja или Visual Studio "
            "(сейчас ${CMAKE_GENERATOR}); используйте пресеты из CMakePresets.json.")
    endif()
    if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        message(FATAL_ERROR "${TASK}: Apple Clang не собирает модули C++20 через CMake (нет clang-scan-deps). "
            "Используйте LLVM Clang из Homebrew — пресет llvm-debug — "
            "или верните решение в include/${NAME}.hpp и src/${NAME}.cpp.")
    endif()

    add_library(${TASK}-lib)
    target_sources(${TASK}-lib PUBLIC FILE_SET CXX_MODULES FILES ${_module})
    target_compile_definitions(${TASK}-lib PUBLIC CPPLABS_USE_MODULES)

    # Программа и тесты задачи импортируют модуль: CMake должен искать в них объявления import.
    # Переменные действуют на цели, которые CMakeLists.txt задачи создаёт после этого вызова
    set(CMAKE_CXX_SCAN_FOR_MODULES ON PARENT_SCOPE)
    # clang-tidy разбирает import, только если программа собирается Clang той же версии:
    # интерфейс модуля, скомпилированный g++ или MSVC, он прочитать не может
    if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_CLANG_TIDY)
        message(WARNING "${TASK}: решение-модуль собирается ${CMAKE_CXX_COMPILER_ID} — clang-tidy для задачи "
            "отключён. Чтобы проверить стиль, соберите задачу Clang: пресет clang-debug или контейнер.")
        set_target_properties(${TASK}-lib PROPERTIES CXX_CLANG_TIDY "")
        set(CMAKE_CXX_CLANG_TIDY "" PARENT_SCOPE)
    endif()
endfunction()
