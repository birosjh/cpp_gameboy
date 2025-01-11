#include "call.h"
#include "jump.h"

uint16_t CALL::address(CPU& cpu, MemoryBus& memory_bus, uint16_t value) {

    auto decremented_sp = cpu.sp() - 2;

    auto first = value & 0xFF;
    auto second = value >> 8;
    
    memory_bus.write_to_memory(decremented_sp, first);
    memory_bus.write_to_memory(decremented_sp + 1, second);

    JP::to_address(cpu, value);

    return cpu.pc() + 1;

}

uint16_t address_if_flag_state(CPU& cpu, MemoryBus& memory_bus, FlagState flag_state, uint16_t value) {

    if (flag_state == ZeroOn) {
        if (cpu.flags[Zero]) {
            return CALL::address(cpu, memory_bus, value);
        }
    } else if(flag_state == ZeroOff) {
        if (!cpu.flags[Zero]) {
            return CALL::address(cpu, memory_bus, value);
        }
    } else if(flag_state == CarryOn) {
        if (cpu.flags[Carry]) {
            return CALL::address(cpu, memory_bus, value);
        }
    } else if(flag_state == CarryOff) {
        if (!cpu.flags[Carry]) {
            return CALL::address(cpu, memory_bus, value);
        }
    }

    return cpu.pc() + 3;

}
