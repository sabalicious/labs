cmake_minimum_required(VERSION 3.23)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c "libs/exam/math_/math_.h" "libs/exam/math_/math_.c" "libs/string_/string_.h" "libs/string_/string_.c" "libs/string_/tasks/task1.c" "libs/string_/tasks/task2.c" "libs/string_/tasks/task4.c" "libs/string_/tasks/task5.c" "libs/string_/tasks/task6.c" "libs/string_/tasks/task7.c" "libs/string_/tasks/task8.c" "libs/string_/tasks/task9.c" "libs/string_/tasks/task10.c" "libs/string_/tasks/task11.c" "libs/string_/tasks/task12.c" "libs/string_/tasks/task13.c" "libs/string_/tasks/task14.c" "libs/string_/tasks/task15.c" "libs/string_/tasks/task16.c" "libs/string_/tasks/task17.c" "libs/string_/tasks/task18.c" "libs/string_/tasks/task19.c" "libs/string_/tests.c" "libs/string_/tasks/tests_tassk.c" "libs/file_processing/task1.c" "libs/file_processing/task2.c" "libs/file_processing/task3.c" "libs/file_processing/task4.c" "libs/file_processing/task5.c" "libs/file_processing/task6.c" "libs/file_processing/task7.c" "libs/file_processing/task8.c" "libs/file_processing/task9.c" "libs/file_processing/task10.c" "libs/file_processing/20lab/task1.c" "libs/file_processing/20lab/task2.c" "libs/file_processing/20lab/task3.c" "libs/file_processing/20lab/task4.c" "libs/file_processing/20lab/task5.c" "libs/file_processing/20lab/task6.c" "libs/file_processing/20lab/task7.c" "libs/file_processing/20lab/task8.c" "libs/file_processing/20lab/task9.c" "libs/file_processing/20lab/task10.c")

add_subdirectory(libs)

target_link_libraries(untitled data_structures)
target_link_libraries(untitled algorithms)
target_link_libraries(untitled exam) #Addm library exam
