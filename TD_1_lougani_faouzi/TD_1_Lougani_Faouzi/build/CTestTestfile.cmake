# CMake generated Testfile for 
# Source directory: /home/lougani/Bureau/td1
# Build directory: /home/lougani/Bureau/td1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/home/lougani/Bureau/td1/build/Test.exe[1]_include.cmake")
add_test(AllTestInTest "Test.exe")
set_tests_properties(AllTestInTest PROPERTIES  _BACKTRACE_TRIPLES "/home/lougani/Bureau/td1/CMakeLists.txt;22;add_test;/home/lougani/Bureau/td1/CMakeLists.txt;0;")
subdirs("mylib")
