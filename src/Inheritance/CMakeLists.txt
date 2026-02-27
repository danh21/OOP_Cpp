file(GLOB CLASS_SRC *.cpp)

add_library(inheritance ${CLASS_SRC})

target_include_directories(inheritance PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
