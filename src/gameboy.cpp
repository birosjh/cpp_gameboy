#include "disassembler.h"

#include <iostream>
#include <string>

int main() {
    
    Disassembler disassembler;

    std::string value = "0x00";

    std::cout << disassembler.interpret(value) << std::endl;

}