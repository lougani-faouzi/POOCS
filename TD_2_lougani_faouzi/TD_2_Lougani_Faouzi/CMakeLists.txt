cmake_minimum_required(VERSION 3.10)

# set the project name
project(faouzilougani) 

find_package(GTest REQUIRED)


# add the executable
add_executable(Main.exe main.cpp)
add_executable(Test.exe test.cpp)

target_link_libraries(Test.exe GTest::GTest GTest::Main)
target_include_directories(Test.exe PUBLIC "${PROJECT_SOURCE_DIR}")

target_link_libraries(Main.exe)
target_include_directories(Main.exe PUBLIC "${PROJECT_SOURCE_DIR}")


add_test(AllTestInTest Test.exe)
enable_testing()

gtest_discover_tests(Test.exe)


