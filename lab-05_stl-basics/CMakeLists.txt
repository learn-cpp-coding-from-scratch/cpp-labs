# --- Лабораторная работа 05. Базовые элементы STL ---
# Google Test подключает корневой CMakeLists.txt
# TASK — префикс имён целей задачи: программа ${TASK}_<slug>;
# у задач с открытыми тестами — тесты ${TASK}-tests;
# add_student_tests — тесты студента tests/student/ (cmake/StudentTests.cmake)

set(TASK lab-05-seminar-01)
add_subdirectory(seminar-01_multiset-operations)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-01_multiset-operations)

set(TASK lab-05-seminar-02)
add_subdirectory(seminar-02_distinct-strings)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-02_distinct-strings)

set(TASK lab-05-seminar-03)
add_subdirectory(seminar-03_word-frequency)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-03_word-frequency)

set(TASK lab-05-seminar-04)
add_subdirectory(seminar-04_substring-search)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-04_substring-search)

set(TASK lab-05-task-01)
add_subdirectory(task-01_multiset-queries)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-01_multiset-queries)

set(TASK lab-05-task-02)
add_subdirectory(task-02_periodic-tasks)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-02_periodic-tasks)

set(TASK lab-05-task-03)
add_subdirectory(task-03_street-surnames)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-03_street-surnames)

set(TASK lab-05-task-04)
add_subdirectory(task-04_merge-minimums)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-04_merge-minimums)
