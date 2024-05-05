#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <vector>
#include <iostream>

#include "cartridge.h"

class Interpreter {

    private:

        std::string Interpreter::to_hex(const int code);

    public:

        uint8_t read_next(const std::vector<char>& game);

};

#endif  // INTERPRETER_H