# Образ контейнера разработки курса: те же инструменты, что в SETUP.md, раздел 1,
# но одной версии у всех. Готовый образ собирает GitHub Actions репозитория cpp-labs
# (.github/workflows/devcontainer-image.yml) и публикует как
# ghcr.io/learn-cpp-coding-from-scratch/cpp-labs-dev с тегом-версией из devcontainer.json;
# devcontainer.json скачивает его. После изменения этого файла увеличьте версию в devcontainer.json.
#
# Локальная сборка (проверить изменения до публикации) — с той же меткой, что в devcontainer.json,
# тогда VS Code (Dev Containers: Rebuild Container) возьмёт этот образ, а не скачает опубликованный:
#   docker build -t ghcr.io/learn-cpp-coding-from-scratch/cpp-labs-dev:2026.1 .devcontainer

# Ubuntu 26.04 LTS: g++ 15, CMake 4.2, Ninja 1.13 из пакетов системы
FROM ubuntu:26.04

ARG LLVM_VERSION=23
ARG GCC_VERSION=15
ARG GTEST_TAG=v1.18.0
ARG SPDLOG_TAG=v1.17.0
ARG CATCH2_TAG=v3.15.1
ARG BAZELISK_VERSION=v1.29.0

LABEL org.opencontainers.image.source="https://github.com/learn-cpp-coding-from-scratch/cpp-labs"
LABEL org.opencontainers.image.description="Clang и g++, CMake, Ninja, Bazel, clang-tidy, clang-format, Google Test, Catch2 и spdlog для лабораторных cpp-labs"

# CC и CXX — компилятор по умолчанию для CMake и Bazel: Clang той же версии, что clang-tidy.
# Только с ним clang-tidy проверяет решения в виде модулей C++20 (import). g++ тоже установлен:
# собрать им — cmake --preset debug -DCMAKE_CXX_COMPILER=g++ (в новой папке сборки)
ENV DEBIAN_FRONTEND=noninteractive \
    LANG=C.UTF-8 \
    LC_ALL=C.UTF-8 \
    CC=clang \
    CXX=clang++

# Компилятор g++ (и стандартная библиотека libstdc++, которой пользуется и Clang), отладчик gdb,
# CMake, Ninja, Git, GitHub CLI
RUN apt-get update && apt-get install -y --no-install-recommends \
        ca-certificates curl gnupg less sudo \
        g++-${GCC_VERSION} gdb cmake ninja-build git gh \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-${GCC_VERSION} 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-${GCC_VERSION} 100 \
    && update-alternatives --install /usr/bin/cc cc /usr/bin/gcc-${GCC_VERSION} 100 \
    && update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++-${GCC_VERSION} 100 \
    && rm -rf /var/lib/apt/lists/*

# clang-tidy и clang-format из репозитория проекта LLVM (apt.llvm.org): в Ubuntu версия старее,
# а нужна та же, что у преподавателя, — иначе замечания clang-tidy будут различаться
# Clang той же версии (с clang-scan-deps из clang-tools: CMake находит им import модулей C++20) —
# компилятор по умолчанию (CC, CXX выше)
RUN curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key \
        | gpg --dearmor -o /usr/share/keyrings/llvm.gpg \
    && echo "deb [signed-by=/usr/share/keyrings/llvm.gpg] http://apt.llvm.org/resolute/ llvm-toolchain-resolute-${LLVM_VERSION} main" \
        > /etc/apt/sources.list.d/llvm.list \
    && apt-get update && apt-get install -y --no-install-recommends \
        clang-tidy-${LLVM_VERSION} clang-format-${LLVM_VERSION} \
        clang-${LLVM_VERSION} clang-tools-${LLVM_VERSION} \
    && ln -s /usr/bin/clang-tidy-${LLVM_VERSION} /usr/local/bin/clang-tidy \
    && ln -s /usr/bin/clang-format-${LLVM_VERSION} /usr/local/bin/clang-format \
    && ln -s /usr/bin/clang-${LLVM_VERSION} /usr/local/bin/clang \
    && ln -s /usr/bin/clang++-${LLVM_VERSION} /usr/local/bin/clang++ \
    && ln -s /usr/bin/clang-scan-deps-${LLVM_VERSION} /usr/local/bin/clang-scan-deps \
    && rm -rf /var/lib/apt/lists/*

# Google Test той же версии, что в cmake/Dependencies.cmake: find_package находит его,
# и при настройке проекта ничего не скачивается (так же spdlog ниже)
RUN curl -fsSL https://github.com/google/googletest/archive/refs/tags/${GTEST_TAG}.tar.gz \
        | tar -xz -C /tmp \
    && cmake -S /tmp/googletest-* -B /tmp/gtest-build -G Ninja \
        -DCMAKE_BUILD_TYPE=Release -DBUILD_GMOCK=OFF \
    && cmake --build /tmp/gtest-build \
    && cmake --install /tmp/gtest-build \
    && rm -rf /tmp/googletest-* /tmp/gtest-build

# Catch2 той же версии, что в cmake/Dependencies.cmake: на нём студент может писать свои тесты
RUN curl -fsSL https://github.com/catchorg/Catch2/archive/refs/tags/${CATCH2_TAG}.tar.gz \
        | tar -xz -C /tmp \
    && cmake -S /tmp/Catch2-* -B /tmp/catch2-build -G Ninja \
        -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF \
    && cmake --build /tmp/catch2-build \
    && cmake --install /tmp/catch2-build \
    && rm -rf /tmp/Catch2-* /tmp/catch2-build

# spdlog той же версии, что в cmake/Dependencies.cmake (со встроенной библиотекой fmt)
RUN curl -fsSL https://github.com/gabime/spdlog/archive/refs/tags/${SPDLOG_TAG}.tar.gz \
        | tar -xz -C /tmp \
    && cmake -S /tmp/spdlog-* -B /tmp/spdlog-build -G Ninja \
        -DCMAKE_BUILD_TYPE=Release -DSPDLOG_BUILD_EXAMPLE=OFF \
    && cmake --build /tmp/spdlog-build \
    && cmake --install /tmp/spdlog-build \
    && rm -rf /tmp/spdlog-* /tmp/spdlog-build

# Bazelisk — запускает Bazel той версии, что в .bazelversion (сборка Bazel — по желанию, тема 4.1).
# Сам Bazel скачивается при первом запуске команды bazel
RUN curl -fsSL -o /usr/local/bin/bazel \
        https://github.com/bazelbuild/bazelisk/releases/download/${BAZELISK_VERSION}/bazelisk-linux-$(dpkg --print-architecture) \
    && chmod +x /usr/local/bin/bazel

# Пользователь ubuntu (uid 1000) уже есть в образе: работаем не от root,
# чтобы файлы сборки в папке репозитория не принадлежали root
RUN echo "ubuntu ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/ubuntu
USER ubuntu
