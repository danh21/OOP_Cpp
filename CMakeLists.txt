cmake_minimum_required(VERSION 3.10.0)
project(OOP_Cpp VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(src/Class_Declaration_and_Definition)
add_subdirectory(src/Operator_overloading)

add_executable(OOP_Cpp main.cpp)

target_link_libraries(OOP_Cpp 
PRIVATE
class
overloading
)

# Target a specific file
add_executable(test_account src/Class_Declaration_and_Definition/Account.cpp)
target_link_libraries(test_account PRIVATE class)
