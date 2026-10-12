# --- Лабораторная работа 02. Алгоритмы ветвления ---
# Google Test подключает корневой CMakeLists.txt
# TASK — префикс имён целей задачи: программа ${TASK}_<slug>;
# у задач с открытыми тестами — тесты ${TASK}-tests;
# add_student_tests — тесты студента tests/student/ (cmake/StudentTests.cmake)

set(TASK lab-02-seminar-05)
add_subdirectory(seminar-05_previous-date)

set(TASK lab-02-task-03)
add_subdirectory(task-03_circles-intersection)
