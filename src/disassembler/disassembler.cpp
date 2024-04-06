#include "disassembler.h"

#include <string>

std::string Disassembler::interpret(std::string& code) {

    std::unordered_map<std::string, std::string> commands =
    {
        {"0x00", "NOP"}
    };

    return "NOP";
}