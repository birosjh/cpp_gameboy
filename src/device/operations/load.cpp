#include "load.h"

// -----------------------------------------------
// Load Commands
// -----------------------------------------------


uint16_t LD::single(std::string in_register) {

    auto value = read_from_memory(cpu.pc + 1);

    cpu.registers[in_register] = value;

    return cpu.pc + 2;
}


uint16_t LD::single_from_register(std::string in_register, std::string load_register) {

    cpu.registers[in_register] = cpu.registers[load_register];

    return cpu.pc + 1;
}

uint16_t LD::single_from_address(std::string in_register, std::string address_register) {

    auto address = cpu.registers[address_register];
    auto value = read_from_memory(address);

    cpu.registers[in_register] = value;

    return cpu.pc + 1;
}

uint16_t LD::single_from_address(std::string in_register, std::string symbol, std::string address_register) {

    auto address = cpu.registers[address_register];
    auto value = read_from_memory(address);

    cpu.registers[in_register] = value;

    if (symbol == "+") {
        INC_pair(address_register);
    } else {
        DEC_pair(address_register);
    }

    return cpu.pc + 1;
}

uint16_t LD::single_to_address(std::string address_register, std::string load_register) {

    auto address = cpu.registers[address_register];
    write_to_memory(address, cpu.registers[load_register]);

    return cpu.pc + 1;
}

uint16_t LD::single_to_address(std::string address_register, std::string symbol, std::string load_register) {

    auto address = cpu.registers[address_register];

    write_to_memory(address, cpu.registers[load_register]);

    if (symbol == "+") {
        INC_pair(address_register);
    } else {
        DEC_pair(address_register);
    }

    return cpu.pc + 1;
}

uint16_t LD::single_to_address(std::string address_register) {
    uint16_t address;

    if (address_register == "bc") {
        address = cpu.bc();
    }
    else if (address_register == "de") {
        address = cpu.de();
    }
    else if (address_register == "hl") {
        address = cpu.hl();
    }
    else if (address_register == "sp") {
        address = cpu.sp();
    }

    auto value = read_from_memory(cpu.pc + 1);

    write_to_memory(address, value);
}

uint16_t LD::pair(std::string pair_register) {

    auto value_one = read_from_memory(cpu.pc + 1);
    auto value_two = read_from_memory(cpu.pc + 2);

    uint16_t joined = ((uint16_t)value_one << 8) | value_two;

    if (pair_register == "bc") {
        cpu.bc(joined);
    }
    else if (pair_register == "de") {
        cpu.de(joined);
    }
    else if (pair_register == "hl") {
        cpu.hl(joined);
    }
    else if (pair_register == "sp") {
        cpu.sp(joined);
    }


    return cpu.pc + 3;
}

uint16_t LD::pair_to_next(std::string pair_register) {

    uint16_t value;
    uint8_t top;
    uint8_t bottom;

    if (pair_register == "bc") {
        value = cpu.bc();
    }
    else if (pair_register == "de") {
        value = cpu.de();
    }
    else if (pair_register == "hl") {
        value = cpu.hl();
    }
    else if (pair_register == "sp") {
        value = cpu.sp();
    }

    top = uint8_t(value & 0xFF00 >> 8);
    bottom = uint8_t(value & 0xFF);

    write_to_memory(cpu.pc + 1, top);
    write_to_memory(cpu.pc + 2, bottom);

    return cpu.pc + 3;
}