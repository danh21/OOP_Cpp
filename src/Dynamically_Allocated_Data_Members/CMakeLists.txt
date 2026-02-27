file(GLOB CLASS_SRC *.cpp)

add_library(dynamic ${CLASS_SRC})

target_include_directories(dynamic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
