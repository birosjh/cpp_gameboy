#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <string>
#include <unordered_map>


class Disassembler {

    public:

        std::string interpret(std::string& code);

};

#endif  // DISASSEMBLER_H