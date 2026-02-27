file(GLOB CLASS_SRC *.cpp)

add_library(overloading ${CLASS_SRC})

target_include_directories(overloading PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
