cmake_minimum_required(VERSION 3.16.3)
project(BCF_Task)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)