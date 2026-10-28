# Файлы данных задачи: add_task_data(<цель программы>) кладёт программу в отдельную папку
# build/<пресет>/bin/${TASK}/ и при каждой сборке копирует туда папку data/ задачи.
# Программа находит данные рядом с собой (cpplabs::dataDirectory()), поэтому её можно запускать
# из любой текущей папки и переносить вместе с папкой data/. Отдельная папка для каждой задачи:
# в общей build/bin файлы data/ разных задач с одинаковыми именами заменяли бы друг друга.
# Вызывается в CMakeLists.txt задачи; TASK задаёт CMakeLists.txt лабораторной.
include_guard()

function(add_task_data TARGET)
    set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${TASK})
    # Копирование при каждой сборке: правки файлов в data/ задачи сразу попадают к программе.
    # Файлы, которые программа создала рядом с собой, остаются — копия только дополняет папку
    add_custom_target(${TASK}-data
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/data $<TARGET_FILE_DIR:${TARGET}>/data
        COMMENT "${TASK}: копирование data/ к программе"
    )
    add_dependencies(${TARGET} ${TASK}-data)
endfunction()
