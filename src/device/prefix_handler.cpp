#include "prefix_handler.h"
#include "memory_bus.h"
#include "rotate.h"

void PREFIX_HANDLER::handle(CPU& cpu, MemoryBus& memory_bus, uint8_t command) {
    switch(command) {
        case 0:
            RLC::run(cpu, B);
        case 1:
            RLC::run(cpu, C);
        case 2:
            RLC::run(cpu, D);
        case 3:
            RLC::run(cpu, E);
        case 4:
            RLC::run(cpu, H);
        case 5:
            RLC::run(cpu, L);
        case 6:
            RLC::run(cpu, memory_bus, HL);
        case 7:
            RLC::run(cpu, A);
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
}