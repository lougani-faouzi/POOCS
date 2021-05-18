#include <iostream>
#include "gtest/gtest.h"
#include "mylib.h"


// Create a test case MylibTestPrintTest, of type UnitTest
TEST(UnitTest, MylibTestPrintTest){ 
  // Create an instance of Mylib::MyClass and test print method
  
  MyLib::MyClass ob1{};
  ob1.print();
      
}

// Create a test case MylibTestPrintTest, of type UnitTest
TEST(UnitTest, MylibTestPrintTest1){ 
  // Create an instance of Mylib::MyClass and test print method
  MyLib::MyClass ob2{};
  EXPECT_EQ(ob2.value(),1);

}

