#ifndef GAMEBOY_H
#define GAMEBOY_H

#include "cpu.h"
#include "interpreter.h"
#include "cartridge.h"

class Device {
    private:
        CPU cpu;
        Interpreter interpreter;

    public:
        play(Cartridge cartridge);

};

#endif // GAMEBOY_H