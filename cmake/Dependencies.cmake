# Директива предотвращает повторное включение одного и
# того же файла несколько раз в процессе конфигурации проекта.
include_guard()

# Переопределяемые версии: cmake -B build -DDEPS_GTEST_TAG=v1.17.0 -DDEPS_SPDLOG_TAG=v1.16.0
if(NOT DEPS_GTEST_TAG)
    set(DEPS_GTEST_TAG v1.18.0 CACHE STRING "googletest version")
endif()
if(NOT DEPS_SPDLOG_TAG)
    set(DEPS_SPDLOG_TAG v1.17.0 CACHE STRING "spdlog version")
endif()

# Номер версии без буквы v — для find_package: v1.18.0 → 1.18.0
string(REGEX REPLACE "^v" "" DEPS_GTEST_VERSION "${DEPS_GTEST_TAG}")
string(REGEX REPLACE "^v" "" DEPS_SPDLOG_VERSION "${DEPS_SPDLOG_TAG}")

include(FetchContent)

# FIND_PACKAGE_ARGS (CMake 3.24+): сначала find_package ищет библиотеку,
# установленную менеджером пакетов (brew, apt, pacman), не ниже указанной версии;
# архив скачивается, только если подходящая библиотека не найдена.
# Всегда скачивать, не используя установленные библиотеки:
#   cmake -B build -DFETCHCONTENT_TRY_FIND_PACKAGE_MODE=NEVER
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/${DEPS_GTEST_TAG}.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    FIND_PACKAGE_ARGS ${DEPS_GTEST_VERSION} NAMES GTest   # пакет называется GTest
)
# настройки действуют, только если gtest скачивается
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)   # для Windows и MSVC
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

# Диагностика: откуда взята библиотека. find_package вызывается под именем googletest,
# поэтому переменные GTest_FOUND и GTest_DIR не задаются; googletest_SOURCE_DIR
# задаётся, только если архив скачан
if(googletest_SOURCE_DIR)
    message(STATUS "Dependencies: googletest ${DEPS_GTEST_TAG} — скачана")
else()
    message(STATUS "Dependencies: googletest — установленная (${googletest_DIR})")
endif()

# spdlog — библиотека логирования; цель spdlog::spdlog подключают задачи с логированием.
# Подходит установленная версия 1.x не ниже указанной (spdlog совместим в пределах старшей версии)
FetchContent_Declare(
    spdlog
    URL https://github.com/gabime/spdlog/archive/refs/tags/${DEPS_SPDLOG_TAG}.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    FIND_PACKAGE_ARGS ${DEPS_SPDLOG_VERSION}
)
# настройки действуют, только если spdlog скачивается
set(SPDLOG_INSTALL OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
# Заголовки spdlog подключаются как системные: иначе clang-tidy (HeaderFilterRegex: '.*')
# проверяет и их — больше тысячи замечаний на одну строку spdlog::info(...).
# У установленной библиотеки заголовки и так системные
set(SPDLOG_SYSTEM_INCLUDES ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(spdlog)

if(spdlog_SOURCE_DIR)
    # Скачанная библиотека собирается, только если её подключает хотя бы одна задача
    set_target_properties(spdlog PROPERTIES EXCLUDE_FROM_ALL TRUE)
    message(STATUS "Dependencies: spdlog ${DEPS_SPDLOG_TAG} — скачана")
else()
    message(STATUS "Dependencies: spdlog — установленная (${spdlog_DIR})")
endif()
