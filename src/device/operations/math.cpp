#include "math.h"

//----------------------
// Addition
//----------------------

uint16_t ADD::single_registers(CPU& cpu, Register in_register, Register add_register) {

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (cpu.registers[add_register] & 0xF)) & 0x10) == 0x10;

    cpu.registers[in_register] = cpu.registers[in_register] + cpu.registers[add_register];

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t ADD::to_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address) {

    auto value_from_memory = memory_bus.read_from_memory(address);

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value_from_memory & 0xF)) & 0x10) == 0x10;

    cpu.registers[in_register] = cpu.registers[in_register] + value_from_memory;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;

}

uint16_t ADD::value_to_single(CPU& cpu, MemoryBus& memory_bus, Register in_register) {

    auto value = memory_bus.get_next_in_memory(cpu);

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value & 0xF)) & 0x10) == 0x10;

    cpu.registers[in_register] = cpu.registers[in_register] + value;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;

}

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

uint16_t ADD::signed_integer(CPU& cpu, MemoryBus& memory_bus, DoubleRegister in_register) {

    auto in_register_value = cpu.double_register(in_register);
    int8_t add_register_value = memory_bus.get_next_in_memory(cpu);

    bool half_carry_occured = (((in_register_value & 0xFFF) + (add_register_value & 0xFFF)) & 0x1000) == 0x1000;
    
    std::cout << half_carry_occured << std::endl;

    in_register_value = in_register_value + add_register_value;
    cpu.double_register(in_register, in_register_value);

    cpu.flags[Zero] = in_register_value == 0;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

//----------------------
// Addition with Carry
//----------------------


uint16_t ADC::single_registers(CPU& cpu, Register in_register, Register add_register) {

    auto value = cpu.registers[add_register] + (uint8_t) cpu.flags[Carry];

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value & 0xF)) & 0x10) == 0x10;

    cpu.registers[in_register] = cpu.registers[in_register] + value;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t ADC::to_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address) {

    auto value = memory_bus.read_from_memory(address) + (uint8_t) cpu.flags[Carry];

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value & 0xF)) & 0x10) == 0x10;

    cpu.registers[in_register] = cpu.registers[in_register] + value;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;

}

uint16_t ADC::value_to_single(CPU& cpu, MemoryBus& memory_bus, Register in_register) {

    auto value = memory_bus.get_next_in_memory(cpu);

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value & 0xF)) & 0x10) == 0x10;

    cpu.registers[in_register] = cpu.registers[in_register] + value;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;

}


//----------------------
// Subtraction
//----------------------

uint16_t SUB::single_registers(CPU& cpu, Register in_register, Register add_register) {

    cpu.registers[in_register] = cpu.registers[in_register] - cpu.registers[add_register];

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (cpu.registers[add_register] & 0xF)) & 0x10) == 0x10;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[Negative] = true;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t SUB::from_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address) {

    auto value_from_memory = memory_bus.read_from_memory(address);

    cpu.registers[in_register] = cpu.registers[in_register] - value_from_memory;

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value_from_memory & 0xF)) & 0x10) == 0x10;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[Negative] = true;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t SUB::value_from_single(CPU& cpu, MemoryBus& memory_bus, Register in_register) {

    auto value = memory_bus.get_next_in_memory(cpu);

    cpu.registers[in_register] = cpu.registers[in_register] - value;

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value & 0xF)) & 0x10) == 0x10;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[Negative] = true;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t SBC::from_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address) {

    auto value_from_memory = memory_bus.read_from_memory(address);

    cpu.registers[in_register] = cpu.registers[in_register] - (value_from_memory + cpu.flags[Carry]);

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value_from_memory & 0xF)) & 0x10) == 0x10;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[Negative] = true;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t SBC::single_registers(CPU& cpu, Register in_register, Register add_register) {

    cpu.registers[in_register] = cpu.registers[in_register] - (cpu.registers[add_register] + cpu.flags[Carry]);

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (cpu.registers[add_register] & 0xF)) & 0x10) == 0x10;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[Negative] = true;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t SBC::value_from_single(CPU& cpu, MemoryBus& memory_bus, Register in_register) {

    auto value = memory_bus.get_next_in_memory(cpu);

    cpu.registers[in_register] = cpu.registers[in_register] - (value + cpu.flags[Carry]);

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (value & 0xF)) & 0x10) == 0x10;

    cpu.flags[Zero] = cpu.registers[in_register] == 0;
    cpu.flags[Negative] = true;
    cpu.flags[HalfCarry] = half_carry_occured;

    return cpu.pc() + 1;
}


