# --- Лабораторная работа 08. Классы. Перегрузка операций. Исключения ---
# Google Test подключает корневой CMakeLists.txt
# TASK — префикс имён целей задачи: программа ${TASK}_<slug>;
# у задач с открытыми тестами — тесты ${TASK}-tests;
# add_student_tests — тесты студента tests/student/ (cmake/StudentTests.cmake)

set(TASK lab-08-seminar-01)
add_subdirectory(seminar-01_rational-number)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-01_rational-number)

set(TASK lab-08-task-01)
add_subdirectory(task-01_complex-number)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-01_complex-number)

set(TASK lab-08-task-02)
add_subdirectory(task-02_complex-equality-cpp17)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-02_complex-equality-cpp17)
