# --- Лабораторная работа 09. Динамическое выделение памяти. Перегрузка операций. Исключения ---
# Google Test подключает корневой CMakeLists.txt
# TASK — префикс имён целей задачи: программа ${TASK}_<slug>;
# у задач с открытыми тестами — тесты ${TASK}-tests;
# add_student_tests — тесты студента tests/student/ (cmake/StudentTests.cmake)

set(TASK lab-09-seminar-01)
add_subdirectory(seminar-01_array)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-01_array)

set(TASK lab-09-task-01)
add_subdirectory(task-01_matrix)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-01_matrix)
