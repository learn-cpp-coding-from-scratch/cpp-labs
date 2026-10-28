# --- Лабораторная работа 06. Внутренние сортировки ---
# Google Test подключает корневой CMakeLists.txt
# TASK — префикс имён целей задачи: программа ${TASK}_<slug>;
# у задач с открытыми тестами — тесты ${TASK}-tests;
# add_student_tests — тесты студента tests/student/ (cmake/StudentTests.cmake)

set(TASK lab-06-task-01)
add_subdirectory(task-01_sorting-algorithms)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-01_sorting-algorithms)
