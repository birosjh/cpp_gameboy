#include "jump.h"

std::unordered_map<Vector, uint16_t> vector_values {
    {x00, 0x0000},
    {x08, 0x0008},
    {x10, 0x0010},
    {x18, 0x0018},
    {x20, 0x0020},
    {x28, 0x0028},
    {x30, 0x0030},
    {x38, 0x0038}
};

uint16_t JP::to_address(CPU& cpu, uint16_t address) {

    cpu.pc(address);
    
    return cpu.pc() + 3;
}

uint16_t JP::to_address_from_value(CPU& cpu, MemoryBus& memory_bus) {
    uint8_t right_half = memory_bus.get_next_in_memory(cpu);
    uint8_t left_half = memory_bus.get_next_in_memory(cpu);

    uint16_t address = left_half | right_half << 8;

    cpu.pc(address);
    
    return cpu.pc() + 3;
}

uint16_t JP::to_address_in_register(CPU& cpu, DoubleRegister in_register) {
    auto address = cpu.double_register(in_register);

    JP::to_address(cpu, address);

    return cpu.pc() + 1;
}

uint16_t JP::to_address_from_value_if_flag_state(CPU& cpu, MemoryBus& memory_bus, FlagState flag_state) {

    if (flag_state == ZeroOn) {
        if (cpu.flags[Zero]) {
            return JP::to_address_from_value(cpu, memory_bus);
        }
    } else if(flag_state == ZeroOff) {
        if (!cpu.flags[Zero]) {
            return JP::to_address_from_value(cpu, memory_bus);
        }
    } else if(flag_state == CarryOn) {
        if (cpu.flags[Carry]) {
            return JP::to_address_from_value(cpu, memory_bus);
        }
    } else if(flag_state == CarryOff) {
        if (!cpu.flags[Carry]) {
            return JP::to_address_from_value(cpu, memory_bus);
        }
    }

    return cpu.pc() + 3;
}



uint16_t JR::by_adding(CPU& cpu, MemoryBus& memory_bus) {

    auto value = memory_bus.get_next_in_memory(cpu);

    auto new_pc = cpu.pc() + value;

    cpu.pc(new_pc);
    
    return cpu.pc() + 2;
}


uint16_t JR::by_adding_if_flag(CPU& cpu, MemoryBus& memory_bus, Flag flag) {

    auto value = memory_bus.get_next_in_memory(cpu);

    if (cpu.flags[flag]) {
        JR::by_adding(cpu, memory_bus);
    }

    return cpu.pc() + 2;
}

uint16_t JR::by_adding_if_not_flag(CPU& cpu, MemoryBus& memory_bus, Flag flag) {

    auto value = memory_bus.get_next_in_memory(cpu);

    if (!cpu.flags[flag]) {
        JR::by_adding(cpu, memory_bus);
    }

    return cpu.pc() + 2;
}

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

uint16_t CALL::address_from_value_if_flag_state(CPU& cpu, MemoryBus& memory_bus, FlagState flag_state) {

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



