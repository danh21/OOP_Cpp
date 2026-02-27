file(GLOB CLASS_SRC *.cpp)

add_library(composed_embed ${CLASS_SRC})

target_include_directories(composed_embed PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
