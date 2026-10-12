# --- Лабораторная работа 03. Циклические алгоритмы ---
# Google Test подключает корневой CMakeLists.txt
# TASK — префикс имён целей задачи: программа ${TASK}_<slug>;
# у задач с открытыми тестами — тесты ${TASK}-tests;
# add_student_tests — тесты студента tests/student/ (cmake/StudentTests.cmake)

set(TASK lab-03-seminar-02)
add_subdirectory(seminar-02_one-bits)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-02_one-bits)

set(TASK lab-03-task-04)
add_subdirectory(task-04_lattice-points)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-04_lattice-points)
