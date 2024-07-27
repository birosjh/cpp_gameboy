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
