cmake_minimum_required(VERSION 3.10)

# set the project name
project(tutorials) 

find_package(GTest REQUIRED)

# add mylib library
add_subdirectory(mylib)


# add the executable
add_executable(Main.exe main.cpp)
add_executable(Test.exe test.cpp)

target_link_libraries(Test.exe PUBLIC mylib GTest::GTest GTest::Main)
target_include_directories(Test.exe PUBLIC "${PROJECT_SOURCE_DIR}/mylib")

target_link_libraries(Main.exe PUBLIC mylib)
target_include_directories(Main.exe PUBLIC "${PROJECT_SOURCE_DIR}/mylib")

add_test(AllTestInTest Test.exe)
enable_testing()
gtest_discover_tests(Test.exe)



