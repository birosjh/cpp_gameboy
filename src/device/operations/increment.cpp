#include "increment.h"

// -----------------------------------------------
// Increment Operation Functions
// -----------------------------------------------

uint16_t INC::single(CPU& cpu, std::string in_register) {

    auto value = cpu.registers[in_register];

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (1 & 0xF)) & 0x10) == 0x10;

    cpu.registers[in_register] = value + 1;

    cpu.flags["z"] = cpu.registers[in_register] == 0;
    cpu.flags["h"] = half_carry_occured;

    return cpu.pc() + 1;
}

uint16_t INC::pair(CPU& cpu, std::string double_register) {

    uint16_t value;

    value = cpu.double_register(double_register);
    cpu.double_register(double_register, value + 1);

    return cpu.pc() + 1;
}

uint16_t INC::address(CPU& cpu, MemoryBus& memory_bus, std::string double_register) {

    uint16_t address;

    address = cpu.double_register(double_register);

    uint8_t value = memory_bus.read_from_memory(address);

    ++value;

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

// -----------------------------------------------
// Decrement Operation Functions
// -----------------------------------------------


uint16_t DEC::single(CPU& cpu, std::string in_register) {

    auto value = cpu.registers[in_register];

    cpu.registers[in_register] = value - 1;

    bool half_carry_occured = (((cpu.registers[in_register] & 0xF) + (1 & 0xF)) & 0x10) == 0x10;

    cpu.flags["z"] = cpu.registers[in_register] == 0;
    cpu.flags["h"] = half_carry_occured;

    return cpu.pc() + 2;
}



uint16_t DEC::pair(CPU& cpu, std::string double_register) {

    uint16_t value;

    value = cpu.double_register(double_register);
    cpu.double_register(double_register, value - 1);

    return cpu.pc() + 1;
}

uint16_t DEC::address(CPU& cpu, MemoryBus& memory_bus, std::string double_register) {

    uint16_t address;

    address = cpu.double_register(double_register);

    uint8_t value = memory_bus.read_from_memory(address);

    --value;

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}