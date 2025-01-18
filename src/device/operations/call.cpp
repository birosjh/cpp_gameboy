#include "call.h"
#include "jump.h"

uint16_t CALL::address_from_value(CPU& cpu, MemoryBus& memory_bus) {

    uint8_t right_half = memory_bus.get_next_in_memory(cpu);
    uint8_t left_half = memory_bus.get_next_in_memory(cpu);

    uint16_t value = left_half | right_half << 8;

    auto decremented_sp = cpu.sp() - 2;
    
    memory_bus.write_to_memory(decremented_sp, right_half);
    memory_bus.write_to_memory(decremented_sp + 1, left_half);

    JP::to_address(cpu, value);

    return cpu.pc() + 1;

}

uint16_t address_if_flag_state(CPU& cpu, MemoryBus& memory_bus, FlagState flag_state, uint16_t value) {

    if (flag_state == ZeroOn) {
        if (cpu.flags[Zero]) {
            return CALL::address_from_value(cpu, memory_bus);
        }
    } else if(flag_state == ZeroOff) {
        if (!cpu.flags[Zero]) {
            return CALL::address_from_value(cpu, memory_bus);
        }
    } else if(flag_state == CarryOn) {
        if (cpu.flags[Carry]) {
            return CALL::address_from_value(cpu, memory_bus);
        }
    } else if(flag_state == CarryOff) {
        if (!cpu.flags[Carry]) {
            return CALL::address_from_value(cpu, memory_bus);
        }
    }

    return cpu.pc() + 3;

}

uint16_t RST::vector(CPU& cpu, MemoryBus& memory_bus, Vector vector) {

    auto address = vector_values[vector];

    auto right_half = address & 0xFF00;
    auto left_half = address << 8;

    auto decremented_sp = cpu.sp() - 2;
    
    memory_bus.write_to_memory(decremented_sp, right_half);
    memory_bus.write_to_memory(decremented_sp + 1, left_half);

    JP::to_address(cpu, address);

    return cpu.pc() + 1;
}
