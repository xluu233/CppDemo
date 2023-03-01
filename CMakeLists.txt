cmake_minimum_required(VERSION 3.20)
project(CppDemo)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        CppDemo/include
        )

add_executable(CppDemo main.cpp)

add_executable(vector vector/vector.cpp)
add_executable(vector_operate vector/vector_operate.cpp)
add_executable(exception try-catch/exception.cpp)
add_executable(try_catch try-catch/try_catch.cpp)
add_executable(time_mutex thread/time_mutex.cpp)
add_executable(swap thread/swap.cpp)
add_executable(mutex thread/mutex.cpp)
add_executable(lock_guard thread/lock_guard.cpp)
add_executable(jthreead thread/jthreead.cpp)
add_executable(base_thread thread/base_thread.cpp)
add_executable(reference ref/reference.cpp)
add_executable(smart_ptr ptr/smart_ptr.cpp)
add_executable(file file/file.cpp)
add_executable(virtual virtual/virtual.cpp)
add_executable(template template/template.cpp)
add_executable(string_test string/string_test.cpp)