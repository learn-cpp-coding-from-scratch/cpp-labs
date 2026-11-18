# Директива предотвращает повторное включение одного и
# того же файла несколько раз в процессе конфигурации проекта.
include_guard()

# Переопределяемые версии: cmake -B build -DDEPS_GTEST_TAG=v1.17.0 -DDEPS_SPDLOG_TAG=v1.16.0 -DDEPS_CATCH2_TAG=v3.14.0
if(NOT DEPS_GTEST_TAG)
    set(DEPS_GTEST_TAG v1.18.0 CACHE STRING "googletest version")
endif()
if(NOT DEPS_SPDLOG_TAG)
    set(DEPS_SPDLOG_TAG v1.17.0 CACHE STRING "spdlog version")
endif()
if(NOT DEPS_CATCH2_TAG)
    set(DEPS_CATCH2_TAG v3.15.1 CACHE STRING "Catch2 version")   # та же, что в MODULE.bazel
endif()

# Номер версии без буквы v — для find_package: v1.18.0 → 1.18.0
string(REGEX REPLACE "^v" "" DEPS_GTEST_VERSION "${DEPS_GTEST_TAG}")
string(REGEX REPLACE "^v" "" DEPS_SPDLOG_VERSION "${DEPS_SPDLOG_TAG}")
string(REGEX REPLACE "^v" "" DEPS_CATCH2_VERSION "${DEPS_CATCH2_TAG}")

# Откуда берётся библиотека — по порядку, до первого подходящего варианта:
#   1. установленная менеджером пакетов (brew, apt, pacman, vcpkg) не ниже указанной версии — find_package;
#   2. архив, уже скачанный в общую папку DEPS_CACHE_DIR, — любой папкой сборки (пресетом)
#      этого или другого проекта с тем же Dependencies.cmake;
#   3. архив скачивается с GitHub один раз и кладётся в DEPS_CACHE_DIR.
# Внутри одной папки сборки FetchContent и так не распаковывает архив повторно.
#
# Всегда брать архив, не используя установленные библиотеки:
#   cmake --preset debug -DFETCHCONTENT_TRY_FIND_PACKAGE_MODE=NEVER
# Своя папка для архивов: cmake --preset debug -DDEPS_CACHE_DIR=/путь/к/папке
if(DEFINED ENV{XDG_CACHE_HOME})
    set(_deps_cache_default "$ENV{XDG_CACHE_HOME}/cpp-deps")
elseif(DEFINED ENV{HOME})
    set(_deps_cache_default "$ENV{HOME}/.cache/cpp-deps")
elseif(DEFINED ENV{LOCALAPPDATA})                   # Windows
    set(_deps_cache_default "$ENV{LOCALAPPDATA}/cpp-deps")
else()
    set(_deps_cache_default "${CMAKE_BINARY_DIR}/_deps-cache")
endif()
set(DEPS_CACHE_DIR "${_deps_cache_default}" CACHE PATH "Папка для скачанных архивов зависимостей")
file(TO_CMAKE_PATH "${DEPS_CACHE_DIR}" DEPS_CACHE_DIR)

# _deps_archive(<результат> <имя файла> <URL>): путь к архиву в DEPS_CACHE_DIR;
# архива нет — скачивает его. Скачивание идёт во временный файл: прерванная загрузка
# не оставит в папке повреждённый архив
function(_deps_archive OUT_VAR FILE_NAME URL)
    set(_archive "${DEPS_CACHE_DIR}/${FILE_NAME}")
    if(NOT EXISTS "${_archive}")
        message(STATUS "Dependencies: скачивание ${URL}")
        file(DOWNLOAD "${URL}" "${_archive}.part" STATUS _status TLS_VERIFY ON)
        list(GET _status 0 _code)
        if(NOT _code EQUAL 0)
            file(REMOVE "${_archive}.part")
            list(GET _status 1 _message)
            message(FATAL_ERROR "Dependencies: не удалось скачать ${URL}: ${_message}")
        endif()
        file(RENAME "${_archive}.part" "${_archive}")
    endif()
    set(${OUT_VAR} "${_archive}" PARENT_SCOPE)
endfunction()

include(FetchContent)

# Установленные библиотеки ищутся, если это не запрещено
if(FETCHCONTENT_TRY_FIND_PACKAGE_MODE STREQUAL "NEVER")
    set(_deps_try_installed OFF)
else()
    set(_deps_try_installed ON)
endif()

# Google Test — фреймворк тестов преподавателя
if(_deps_try_installed)
    find_package(GTest ${DEPS_GTEST_VERSION} QUIET CONFIG)
endif()
if(GTest_FOUND)
    message(STATUS "Dependencies: googletest — установленная (${GTest_DIR})")
else()
    _deps_archive(_gtest_archive "googletest-${DEPS_GTEST_TAG}.zip"
        "https://github.com/google/googletest/archive/refs/tags/${DEPS_GTEST_TAG}.zip")
    # настройки действуют, только если gtest собирается из архива
    set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)   # для Windows и MSVC
    FetchContent_Declare(googletest URL "${_gtest_archive}" DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
    FetchContent_MakeAvailable(googletest)
    message(STATUS "Dependencies: googletest ${DEPS_GTEST_TAG} — архив ${_gtest_archive}")
endif()

enable_testing()
include(GoogleTest)

# spdlog — библиотека логирования; цель spdlog::spdlog подключают задачи с логированием.
# Подходит установленная версия 1.x не ниже указанной (spdlog совместим в пределах старшей версии)
if(_deps_try_installed)
    find_package(spdlog ${DEPS_SPDLOG_VERSION} QUIET CONFIG)
endif()
if(spdlog_FOUND)
    message(STATUS "Dependencies: spdlog — установленная (${spdlog_DIR})")
else()
    _deps_archive(_spdlog_archive "spdlog-${DEPS_SPDLOG_TAG}.tar.gz"
        "https://github.com/gabime/spdlog/archive/refs/tags/${DEPS_SPDLOG_TAG}.tar.gz")
    # настройки действуют, только если spdlog собирается из архива
    set(SPDLOG_INSTALL OFF CACHE BOOL "" FORCE)
    set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
    # Заголовки spdlog подключаются как системные: иначе clang-tidy (HeaderFilterRegex: '.*')
    # проверяет и их — больше тысячи замечаний на одну строку spdlog::info(...).
    # У установленной библиотеки заголовки и так системные
    set(SPDLOG_SYSTEM_INCLUDES ON CACHE BOOL "" FORCE)
    FetchContent_Declare(spdlog URL "${_spdlog_archive}" DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
    FetchContent_MakeAvailable(spdlog)
    # Библиотека из архива собирается, только если её подключает хотя бы одна задача
    set_target_properties(spdlog PROPERTIES EXCLUDE_FROM_ALL TRUE)
    message(STATUS "Dependencies: spdlog ${DEPS_SPDLOG_TAG} — архив ${_spdlog_archive}")
endif()

# Catch2 — второй фреймворк тестирования: на нём студент может писать свои тесты
# tests/student/ (cmake/StudentTests.cmake). Тесты преподавателя — на Google Test.
# Подходит установленная версия 3.x не ниже указанной; её Catch2Config.cmake сам добавляет
# модуль Catch.cmake (catch_discover_tests) в CMAKE_MODULE_PATH
if(_deps_try_installed)
    find_package(Catch2 ${DEPS_CATCH2_VERSION} QUIET CONFIG)
endif()
if(Catch2_FOUND)
    message(STATUS "Dependencies: Catch2 — установленная (${Catch2_DIR})")
else()
    _deps_archive(_catch2_archive "Catch2-${DEPS_CATCH2_TAG}.tar.gz"
        "https://github.com/catchorg/Catch2/archive/refs/tags/${DEPS_CATCH2_TAG}.tar.gz")
    FetchContent_Declare(Catch2 URL "${_catch2_archive}" DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
    FetchContent_MakeAvailable(Catch2)
    # Библиотека из архива собирается, только если на Catch2 написан хотя бы один тест;
    # модуль Catch.cmake лежит в папке extras архива
    set_target_properties(Catch2 Catch2WithMain PROPERTIES EXCLUDE_FROM_ALL TRUE)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    message(STATUS "Dependencies: Catch2 ${DEPS_CATCH2_TAG} — архив ${_catch2_archive}")
endif()
include(Catch)
