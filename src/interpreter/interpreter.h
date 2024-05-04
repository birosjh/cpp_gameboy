#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <vector>
#include <iostream>


class Interpreter {

    private:

        void lookup_command(const int code);
        std::string Interpreter::to_hex(const int code);

    public:

        void interpret(const std::vector<char>& game);

};

#endif  // INTERPRETER_H