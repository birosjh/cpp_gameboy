#include "stack.h"

uint16_t POP::register_pair(CPU& cpu, MemoryBus& memory_bus, Register first, Register second) {

    auto decremented_sp = cpu.sp() - 1;
    
    memory_bus.write_to_memory(decremented_sp, cpu.registers[first]);

    decremented_sp -= 1;

    memory_bus.write_to_memory(decremented_sp, cpu.registers[second]);

    cpu.sp(decremented_sp);

    return cpu.pc() + 1;
}

uint16_t PUSH::register_pair(CPU& cpu, MemoryBus& memory_bus, Register first, Register second) {

    auto increment_sp = cpu.sp();
    
    cpu.registers[second] = memory_bus.read_from_memory(increment_sp);
    memory_bus.write_to_memory(increment_sp, 0);

    increment_sp = cpu.sp() + 1;

    cpu.registers[first] = memory_bus.read_from_memory(increment_sp);
    memory_bus.write_to_memory(increment_sp, 0);

    increment_sp += 1;

    cpu.sp(increment_sp);

    return cpu.pc() + 1;
}