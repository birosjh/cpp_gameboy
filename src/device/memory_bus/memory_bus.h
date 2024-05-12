#ifndef MEMORY_BUS_H
#define MEMORY_BUS_H

#include <string>
#include <vector>
#include <iostream>

class MemoryBus {

    public:

        uint8_t read_next(const std::vector<char>& game);

};

#endif  // MEMORY_BUS_H