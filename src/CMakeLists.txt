# add the executable
add_executable(gameboy ${CMAKE_SOURCE_DIR}/src/gameboy.cpp)

set_property(TARGET gameboy PROPERTY CXX_STANDARD 20)
target_compile_options(gameboy PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_subdirectory(cartridge)
add_subdirectory(device)

target_link_libraries(gameboy PUBLIC device cartridge)

