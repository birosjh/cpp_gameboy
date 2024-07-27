#include "math.h"

// Single Registers

uint16_t ADD::single_registers(CPU& cpu, Register in_register, Register add_register) {

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (cpu.registers[add_register] & 0xF)) & 0x10) == 0x10;

    cpu.registers[in_register] = cpu.registers[in_register] + cpu.registers[add_register];

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t ADD::to_single_using_address(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address) {

    auto value_from_memory = memory_bus.read_from_memory(address);

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value_from_memory & 0xF)) & 0x10) == 0x10;

    cpu.registers[in_register] = cpu.registers[in_register] + value_from_memory;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;

}

uint16_t SUB::single_registers(CPU& cpu, Register in_register, Register add_register) {

    cpu.registers[in_register] = cpu.registers[in_register] - cpu.registers[add_register];

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (cpu.registers[add_register] & 0xF)) & 0x10) == 0x10;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[Negative] = true;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t SUB::from_single_using_address(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address) {

    auto value_from_memory = memory_bus.read_from_memory(address);

    cpu.registers[in_register] = cpu.registers[in_register] - value_from_memory;

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value_from_memory & 0xF)) & 0x10) == 0x10;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[Negative] = true;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

// Double Registers

uint16_t ADD::double_registers(CPU& cpu, DoubleRegister in_register, DoubleRegister add_register) {

    auto in_register_value = cpu.double_register(in_register);
    auto add_register_value = cpu.double_register(add_register);

    bool half_carry_occured = (((in_register_value & 0xFFF) + (add_register_value & 0xFFF)) & 0x1000) == 0x1000;
    
    std::cout << half_carry_occured << std::endl;

    in_register_value = in_register_value + add_register_value;
    cpu.double_register(in_register, in_register_value);

    cpu.flags[Zero] = in_register_value == 0;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}