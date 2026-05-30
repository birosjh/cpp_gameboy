#include "logger.h"
#include <iomanip>

bool Log::opcodes_on = true;
bool Log::counter_on = true;

void Log::opcode(std::string name, DoubleRegister in_register, std::string value) {
    if(Log::opcodes_on) {

        auto register_name = double_register_names[in_register];

        std::cout << name << " " << register_name << " " <<  value << std::endl;
    }
}

void Log::counter(CPU& cpu) {
    if(Log::counter_on) {

        std::cout << "Program Counter: " << cpu.pc() << std::endl;
        
    }
}

void Log::code(uint8_t code) {
    std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(code) << std::endl;
}

