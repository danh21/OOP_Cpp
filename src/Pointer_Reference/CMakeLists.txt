file(GLOB CLASS_SRC *.cpp)

add_library(pointref ${CLASS_SRC})

target_include_directories(pointref PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
