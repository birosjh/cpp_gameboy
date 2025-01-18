#include "bool.h"

// AND Ops

uint16_t OR::with(CPU& cpu, uint8_t value) {

    cpu.registers[A] = cpu.registers[A] & value;

    cpu.flags[Zero] = cpu.registers[A] == 0;
    cpu.flags[HalfCarry] = true;

    return cpu.pc() + 1;

}

uint16_t AND::with_value(CPU& cpu, MemoryBus& memory_bus) {

    uint8_t value = memory_bus.get_next_in_memory(cpu);

    OR::with(cpu, value);

}

uint16_t AND::with_register(CPU& cpu, Register compare_register) {

    auto value = cpu.registers[compare_register];

    AND::with(cpu, value);

    return cpu.pc() + 1;
}


uint16_t AND::with_address(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register) {

    auto address = cpu.double_register(address_register);

    auto value = memory_bus.read_from_memory(address);

    AND::with(cpu, value);

    return cpu.pc() + 1;

}

// OR Ops

uint16_t OR::with(CPU& cpu, uint8_t value) {

    cpu.registers[A] = cpu.registers[A] | value;

    cpu.flags[Zero] = cpu.registers[A] == 0;
    cpu.flags[HalfCarry] = true;

    return cpu.pc() + 1;

}

uint16_t OR::with_value(CPU& cpu, MemoryBus& memory_bus) {

    uint8_t value = memory_bus.get_next_in_memory(cpu);

    OR::with(cpu, value);
    
    return cpu.pc() + 1;
    
}

uint16_t OR::with_register(CPU& cpu, Register compare_register) {

    auto value = cpu.registers[compare_register];

    OR::with(cpu, value);

    return cpu.pc() + 1;
}


uint16_t OR::with_address(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register) {

    auto address = cpu.double_register(address_register);

    auto value = memory_bus.read_from_memory(address);

    OR::with(cpu, value);

    return cpu.pc() + 1;

}

// XOR Ops

uint16_t XOR::with(CPU& cpu, uint8_t value) {

    cpu.registers[A] = cpu.registers[A] ^ value;

    cpu.flags[Zero] = cpu.registers[A] == 0;
    cpu.flags[HalfCarry] = true;

    return cpu.pc() + 1;

}

uint16_t XOR::with_value(CPU& cpu, MemoryBus& memory_bus) {

    uint8_t value = memory_bus.get_next_in_memory(cpu);

    XOR::with(cpu, value);
    
    return cpu.pc() + 1;
}

uint16_t XOR::with_register(CPU& cpu, Register compare_register) {

    auto value = cpu.registers[compare_register];

    XOR::with(cpu, value);

    return cpu.pc() + 1;
}


uint16_t XOR::with_address(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register) {

    auto address = cpu.double_register(address_register);

    auto value = memory_bus.read_from_memory(address);

    XOR::with(cpu, value);

    return cpu.pc() + 1;

}
