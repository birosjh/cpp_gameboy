#include "jump.h"

uint16_t JP::to_address(CPU& cpu, uint16_t address) {

    cpu.pc(address);
    
    return cpu.pc() + 3;
}


uint16_t JP::to_address_in_register(CPU& cpu, DoubleRegister in_register) {
    auto address = cpu.double_register(in_register);

    JP::to_address(cpu, address);

    return cpu.pc() + 1;
}

uint16_t JP::to_address_if_flag(CPU& cpu, Flag flag, uint16_t address) {

    if (cpu.flags[flag]) {
        JP::to_address(cpu, address);
    }

    return cpu.pc() + 3;
}



uint16_t JR::by_adding(CPU& cpu, uint8_t value) {

    auto new_pc = cpu.pc() + value;

    cpu.pc(new_pc);
    
    return cpu.pc() + 2;
}


uint16_t JR::by_adding_if_flag(CPU& cpu, Flag flag, uint8_t value) {

    if (cpu.flags[flag]) {
        JR::by_adding(cpu, value);
    }

    return cpu.pc() + 2;
}


