cmake_minimum_required(VERSION 3.15)
project(two_semester_Cplusplus_programming)

set(CMAKE_CXX_STANDARD 20)


add_executable(1_Bottle_all Main/1_Bottle_all.cpp)
add_executable(2_greedy_sequence Main/2_greedy_sequence.cpp)
add_executable(4_heapsort Main/4_heapsort.cpp)

add_executable(bucket_sort AiSD_C/bucket_sort.c)
add_executable(k_statistik AiSD_C/k_statistik.c)
add_executable(lin_logsort AiSD_C/lin_logsort.c)
add_executable(merge_sort AiSD_C/merge_sort.c)
add_executable(search_inversion AiSD_C/search_inversion.c)
add_executable(square_sort AiSD_C/square_sort.c)


add_executable(two_semester_Cplusplus_programming test.cpp)