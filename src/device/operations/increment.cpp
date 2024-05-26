#include "increment.h"

// -----------------------------------------------
// Increment Operation Functions
// -----------------------------------------------

uint16_t INC::single(CPU& cpu, std::string in_register) {

    auto value = cpu.registers[in_register];

    cpu.registers[in_register] = value + 1;

    return cpu.pc() + 2;
}

uint16_t INC::pair(CPU& cpu, std::string double_register) {

    uint16_t value;

    if (double_register == "bc") {
        value = cpu.bc();
        cpu.bc(value + 1);
    }
    else if (double_register == "de") {
        value = cpu.de();
        cpu.de(value + 1);
    }
    else if (double_register == "hl") {
        value = cpu.hl();
        cpu.hl(value + 1);
    }
    else if (double_register == "sp") {
        value = cpu.sp();
        cpu.sp(value - 1);
    }

    return cpu.pc() + 1;
}

uint16_t INC::address(CPU& cpu, MemoryBus& memory_bus, std::string double_register) {

    uint16_t address;

    if (double_register == "bc") {
        address = cpu.bc();
    }
    else if (double_register == "de") {
        address = cpu.de();
    }
    else if (double_register == "hl") {
        address = cpu.hl();
    }
    else if (double_register == "sp") {
        address = cpu.sp();
    }

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

    return cpu.pc() + 2;
}



uint16_t DEC::pair(CPU& cpu, std::string double_register) {

    uint16_t value;

    if (double_register == "bc") {
        value = cpu.bc();
        cpu.bc(value - 1);
    }
    else if (double_register == "de") {
        value = cpu.de();
        cpu.de(value - 1);
    }
    else if (double_register == "hl") {
        value = cpu.hl();
        cpu.hl(value - 1);
    }
    else if (double_register == "sp") {
        value = cpu.sp();
        cpu.sp(value - 1);
    }

    return cpu.pc() + 1;
}

uint16_t DEC::address(CPU& cpu, MemoryBus& memory_bus, std::string double_register) {

    uint16_t address;

    if (double_register == "bc") {
        address = cpu.bc();
    }
    else if (double_register == "de") {
        address = cpu.de();
    }
    else if (double_register == "hl") {
        address = cpu.hl();
    }
    else if (double_register == "sp") {
        address = cpu.sp();
    }

    uint8_t value = memory_bus.read_from_memory(address);

    --value;

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}