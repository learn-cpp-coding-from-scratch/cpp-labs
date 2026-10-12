# Директива предотвращает повторное включение одного и
# того же файла несколько раз в процессе конфигурации проекта.
include_guard()

# Переопределяемая версия: cmake -B build -DDEPS_GTEST_TAG=v1.17.0
if(NOT DEPS_GTEST_TAG)
    set(DEPS_GTEST_TAG v1.18.0 CACHE STRING "googletest version")
endif()

# Номер версии без буквы v — для find_package: v1.18.0 → 1.18.0
string(REGEX REPLACE "^v" "" DEPS_GTEST_VERSION "${DEPS_GTEST_TAG}")

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

# Диагностика: откуда взята библиотека
if(GTest_FOUND)
    message(STATUS "Dependencies: googletest ${GTest_VERSION} — установленная (${GTest_DIR})")
else()
    message(STATUS "Dependencies: googletest ${DEPS_GTEST_TAG} — скачана")
endif()
