# --- Лабораторная работа 01. Линейные алгоритмы ---
# Google Test подключает корневой CMakeLists.txt
# TASK — префикс имён целей задачи: программа ${TASK}_<slug>;
# у задач с открытыми тестами — тесты ${TASK}-tests;
# add_student_tests — тесты студента tests/student/ (cmake/StudentTests.cmake)

set(TASK lab-01-seminar-03)
add_subdirectory(seminar-03_sqrt-sine)

set(TASK lab-01-task-05)
add_subdirectory(task-05_time-of-day)
