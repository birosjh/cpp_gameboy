# add the executable
add_executable(gameboy ${CMAKE_SOURCE_DIR}/src/gameboy.cpp)

set_property(TARGET gameboy PROPERTY CXX_STANDARD 20)
target_compile_options(gameboy PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_library(disassembler STATIC ${CMAKE_SOURCE_DIR}/src/disassembler/disassembler.h ${CMAKE_SOURCE_DIR}/src/disassembler/disassembler.cpp)
target_include_directories(disassembler PUBLIC disassembler)

target_link_libraries(gameboy PUBLIC disassembler)

