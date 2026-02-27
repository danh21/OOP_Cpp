file(GLOB CLASS_SRC *.cpp)

add_library(class ${CLASS_SRC})

target_include_directories(class PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
