# --- Лабораторная работа 04. Функции. Циклические алгоритмы. Коллекции vector, array ---
# Google Test подключает корневой CMakeLists.txt
# TASK — префикс имён целей задачи: программа ${TASK}_<slug>;
# у задач с открытыми тестами — тесты ${TASK}-tests;
# add_student_tests — тесты студента tests/student/ (cmake/StudentTests.cmake)

set(TASK lab-04-seminar-01)
add_subdirectory(seminar-01_means)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-01_means)

set(TASK lab-04-seminar-02)
add_subdirectory(seminar-02_remove-zeros)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-02_remove-zeros)

set(TASK lab-04-seminar-03)
add_subdirectory(seminar-03_sign-order)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-03_sign-order)

set(TASK lab-04-seminar-04)
add_subdirectory(seminar-04_permutation-of-array)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-04_permutation-of-array)

set(TASK lab-04-seminar-05)
add_subdirectory(seminar-05_transpose)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-05_transpose)

set(TASK lab-04-seminar-06)
add_subdirectory(seminar-06_sorting)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/seminar-06_sorting)

set(TASK lab-04-task-01)
add_subdirectory(task-01_missing-digit)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-01_missing-digit)

set(TASK lab-04-task-02)
add_subdirectory(task-02_reverse)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-02_reverse)

set(TASK lab-04-task-03)
add_subdirectory(task-03_one-to-n-permutation)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-03_one-to-n-permutation)

set(TASK lab-04-task-04)
add_subdirectory(task-04_common-elements)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-04_common-elements)

set(TASK lab-04-task-05)
add_subdirectory(task-05_swap-parts)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-05_swap-parts)

set(TASK lab-04-task-06)
add_subdirectory(task-06_matrix-product)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-06_matrix-product)

set(TASK lab-04-task-07)
add_subdirectory(task-07_farey)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-07_farey)

set(TASK lab-04-task-08)
add_subdirectory(task-08_set-sizes)
add_student_tests(${TASK} ${CMAKE_CURRENT_SOURCE_DIR}/task-08_set-sizes)
