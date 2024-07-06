#include <exception>

#include "load.h"

// -----------------------------------------------
// Load Commands
// -----------------------------------------------


uint16_t LD::single_from_single(CPU& cpu, std::string in_register, std::string load_register) {

    cpu.registers[in_register] = cpu.registers[load_register];

    return cpu.pc() + 1;
}


uint16_t LD::single_from_address(CPU& cpu, MemoryBus& memory_bus, std::string in_register, uint16_t address) {


    auto value_at_address = memory_bus.read_from_memory(address);

    cpu.registers[in_register] = value_at_address;

    return cpu.pc() + 1;
}

uint16_t LD::single_from_value(CPU& cpu, std::string in_register, uint8_t value) {

    cpu.registers[in_register] = value;

    return cpu.pc() + 1;
}

uint16_t LD::address_from_single(CPU& cpu, MemoryBus& memory_bus, uint16_t address, std::string load_register) {

    auto value = cpu.registers[load_register];

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t LD::double_from_value(CPU& cpu, std::string in_register, uint16_t value) {

    if(in_register == "bc") {
        cpu.bc(value);
    } else if(in_register == "de") {
        cpu.de(value);
    } else if(in_register == "hl") {
        cpu.hl(value);
    } else if (in_register == "sp") {
        cpu.sp(value);
    } else {
        throw "Register does not exist";
    }

    return cpu.pc() + 1;
}
