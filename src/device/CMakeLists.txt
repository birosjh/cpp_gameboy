add_library(device STATIC device.cpp device.h)
add_library(operations_handler STATIC operations_handler.cpp operations_handler.h)

add_library(cpu STATIC ${CMAKE_CURRENT_SOURCE_DIR}/cpu/cpu.cpp ${CMAKE_CURRENT_SOURCE_DIR}/cpu/cpu.h)
target_include_directories(cpu PUBLIC cpu)

add_library(memory_bus STATIC ${CMAKE_CURRENT_SOURCE_DIR}/memory_bus/memory_bus.cpp ${CMAKE_CURRENT_SOURCE_DIR}/memory_bus/memory_bus.h)
target_include_directories(memory_bus PUBLIC memory_bus)

set(OPERATIONS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/operations)
add_library(operations STATIC
    ${OPERATIONS_DIR}/increment.cpp ${OPERATIONS_DIR}/increment.h
    ${OPERATIONS_DIR}/load.cpp ${OPERATIONS_DIR}/load.h
    ${OPERATIONS_DIR}/math.cpp ${OPERATIONS_DIR}/math.h
    ${OPERATIONS_DIR}/jump.cpp ${OPERATIONS_DIR}/jump.h
    ${OPERATIONS_DIR}/bool.cpp ${OPERATIONS_DIR}/bool.h
    ${OPERATIONS_DIR}/compare.cpp ${OPERATIONS_DIR}/compare.h
    ${OPERATIONS_DIR}/stack.cpp ${OPERATIONS_DIR}/stack.h
)

target_link_libraries(operations PUBLIC cpu memory_bus)
target_include_directories(operations PUBLIC cpu memory_bus)

target_link_libraries(operations_handler PUBLIC cpu memory_bus operations)
target_include_directories(operations_handler PUBLIC cpu memory_bus operations)

target_link_libraries(device PUBLIC cpu memory_bus operations_handler)
target_include_directories(device PUBLIC cpu memory_bus operations_handler)