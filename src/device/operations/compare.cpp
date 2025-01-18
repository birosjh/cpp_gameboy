#include "compare.h"

uint16_t CP::to_value(CPU& cpu, MemoryBus& memory_bus) {

    auto value = memory_bus.get_next_in_memory(cpu);

    auto result = cpu.registers[A] - value;

    bool half_carry_occured = (((result & 0xF) + (value & 0xF)) & 0x10) == 0x10;

    cpu.flags[Zero] = result == 0;
    cpu.flags[Negative] = true;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t CP::to_register(CPU& cpu, Register compare_register) {

    CP::to_value(cpu, cpu.registers[compare_register]);

    return cpu.pc() + 1;
}

uint16_t CP::to_address_value(CPU& cpu, MemoryBus& memory_bus, uint16_t address) {

    auto value = memory_bus.read_from_memory(address);

    CP::to_value(cpu, value);

    return cpu.pc() + 1;
}

