#include "stack.h"

// PUSH Operations

uint16_t PUSH::register_pair(CPU& cpu, MemoryBus& memory_bus, Register first, Register second) {

    auto decremented_sp = cpu.sp() - 1;
    
    memory_bus.write_to_memory(decremented_sp, cpu.registers[first]);

    decremented_sp -= 1;
    
    if(second != F) {
        memory_bus.write_to_memory(decremented_sp, cpu.registers[second]);
    } else{
        memory_bus.write_to_memory(decremented_sp, cpu.f());
    }

    cpu.sp(decremented_sp);

    return cpu.pc() + 1;
}

// POP Operations

uint16_t POP::register_pair(CPU& cpu, MemoryBus& memory_bus, Register first, Register second) {

    auto increment_sp = cpu.sp();
    
    if(second != F) {
        cpu.registers[second] = memory_bus.read_from_memory(increment_sp);
    } else{
        cpu.f(memory_bus.read_from_memory(increment_sp));
    }

    memory_bus.write_to_memory(increment_sp, 0);

    increment_sp = cpu.sp() + 1;

    cpu.registers[first] = memory_bus.read_from_memory(increment_sp);
    memory_bus.write_to_memory(increment_sp, 0);

    increment_sp += 1;

    cpu.sp(increment_sp);

    return cpu.pc() + 1;
}

// RET Operations

int16_t RET::standard(CPU& cpu, MemoryBus& memory_bus) {

    auto increment_sp = cpu.sp();
    
    auto second = memory_bus.read_from_memory(increment_sp);
    memory_bus.write_to_memory(increment_sp, 0);

    increment_sp = cpu.sp() + 1;

    auto first = memory_bus.read_from_memory(increment_sp);
    memory_bus.write_to_memory(increment_sp, 0);

    increment_sp += 1;

    cpu.sp(increment_sp);

    return cpu.pc() + 1;

}

int16_t RET::run(CPU& cpu, MemoryBus& memory_bus, FlagState flag_state) {
    if (flag_state == ZeroOn) {
        if (cpu.flags[Zero]) {
            return RET::run(cpu, memory_bus);
        }
    } else if(flag_state == ZeroOff) {
        if (!cpu.flags[Zero]) {
            return RET::run(cpu, memory_bus);
        }
    } else if(flag_state == CarryOn) {
        if (cpu.flags[Carry]) {
            return RET::run(cpu, memory_bus);
        }
    } else if(flag_state == CarryOff) {
        if (!cpu.flags[Carry]) {
            return RET::run(cpu, memory_bus);
        }
    }

    return cpu.pc() + 1;
}

int16_t RETI::run(CPU& cpu, MemoryBus& memory_bus) {
    EI::run(cpu);
    RET::run(cpu, memory_bus);

    return cpu.pc() + 1;
}