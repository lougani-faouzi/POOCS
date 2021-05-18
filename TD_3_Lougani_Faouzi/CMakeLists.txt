cmake_minimum_required(VERSION 3.16)

# set the project name
project(TD) 

#find_package(GTest REQUIRED)



# add the executable
add_executable(Main.exe main_TD.cpp Simulator.h SteadySimulator.h UnsteadySimulator.h Particles.h)
#add_executable(Test.exe test_TD.cpp UnsteadySimulator.h Particles.h)




#target_link_libraries(Test.exe PUBLIC GTest::GTest GTEST::Main)
#target_include_directories(Test.exe PUBLIC ${GTEST_INCLUDE_DIRS})



#add_test(AllTestInTest Test.exe)


#gtest_discover_tests(Test.exe)

#enable_testing()

