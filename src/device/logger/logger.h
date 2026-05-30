#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

#include "cpu.h"

namespace Log {

    extern bool opcodes_on;
    extern bool counter_on;
    
    void code(uint8_t code);
    void opcode(std::string name, DoubleRegister double_register, std::string value);
    void counter(CPU& cpu);
}



#endif // LOGGER_H