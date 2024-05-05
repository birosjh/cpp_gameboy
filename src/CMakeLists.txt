# add the executable
add_executable(gameboy ${CMAKE_SOURCE_DIR}/src/gameboy.cpp)

set_property(TARGET gameboy PROPERTY CXX_STANDARD 20)
target_compile_options(gameboy PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_library(interpreter STATIC ${CMAKE_SOURCE_DIR}/src/interpreter/interpreter.h ${CMAKE_SOURCE_DIR}/src/interpreter/interpreter.cpp)
target_include_directories(interpreter PUBLIC interpreter)

target_link_libraries(gameboy PUBLIC interpreter)

