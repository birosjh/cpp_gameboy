enable_testing()

# Google Test Setup
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(
  gameboy_test
  test_gameboy.cpp
  test_increment.cpp
  test_load.cpp
)
target_compile_options(gameboy_test PRIVATE -Wall -Wextra -Wpedantic -Werror)

target_link_libraries(
  gameboy_test PUBLIC
  operations
  GTest::gtest_main
)
target_include_directories(
  gameboy_test PUBLIC
  ${CMAKE_SOURCE_DIR}/src/device/operations
)

include(GoogleTest)
gtest_discover_tests(gameboy_test)