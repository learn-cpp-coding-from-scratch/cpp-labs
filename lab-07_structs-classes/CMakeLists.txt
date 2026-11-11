# --- Лабораторная работа 07. Структуры и классы ---
# Google Test подключает корневой CMakeLists.txt
# TASK — префикс имён целей задачи: программа ${TASK}_<slug>;
# у задач с открытыми тестами — тесты ${TASK}-tests;
# add_student_tests — тесты студента tests/student/ (cmake/StudentTests.cmake)

set(TASK lab-07-task-01)
add_subdirectory(task-01_country-populations)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-01_country-populations)
