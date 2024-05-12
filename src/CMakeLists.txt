# add the executable
add_executable(gameboy ${CMAKE_SOURCE_DIR}/src/gameboy.cpp)

set_property(TARGET gameboy PROPERTY CXX_STANDARD 20)
target_compile_options(gameboy PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_subdirectory(cartridge)
add_subdirectory(device)

target_include_directories(device PUBLIC cartridge)
target_link_libraries(device PUBLIC cartridge)

target_include_directories(gameboy PRIVATE cartridge device)
target_link_libraries(gameboy PUBLIC cartridge device)


