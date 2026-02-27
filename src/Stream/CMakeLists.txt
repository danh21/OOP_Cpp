file(GLOB CLASS_SRC *.cpp)

add_library(stream ${CLASS_SRC})

target_include_directories(stream PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
