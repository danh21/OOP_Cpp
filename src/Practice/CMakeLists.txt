file(GLOB CLASS_SRC *.cpp)

add_library(practice ${CLASS_SRC})

target_include_directories(practice PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
