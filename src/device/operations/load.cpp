#include <exception>

#include "load.h"
#include "increment.h"

// -----------------------------------------------
// Load Commands
// -----------------------------------------------


uint16_t LD::single_from_single(CPU& cpu, Register in_register, Register load_register) {

    cpu.registers[in_register] = cpu.registers[load_register];

    return cpu.pc() + 1;
}


uint16_t LD::single_from_address(CPU& cpu, MemoryBus& memory_bus, Register in_register, DoubleRegister address_register) {

    auto address = cpu.double_register(address_register);

    auto value_at_address = memory_bus.read_from_memory(address);

    cpu.registers[in_register] = value_at_address;

    return cpu.pc() + 1;
}

uint16_t LD::single_from_address(CPU& cpu, MemoryBus& memory_bus, Register in_register, DoubleRegister address_register, Modifier modifier) {

    auto address = cpu.double_register(address_register);

    auto value_at_address = memory_bus.read_from_memory(address);

    cpu.registers[in_register] = value_at_address;

    if(modifier == Inc) {
        INC::pair(cpu, address_register);
    } else {
        DEC::pair(cpu, address_register);
    }

    return cpu.pc() + 1;
}

uint16_t LD::single_from_value(CPU& cpu, Register in_register, uint8_t value) {

    cpu.registers[in_register] = value;

    return cpu.pc() + 1;
}

uint16_t LD::to_address_from_single(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register, Register load_register) {

    auto address = cpu.double_register(address_register);

    auto value = cpu.registers[load_register];

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t LD::to_address_from_single(CPU& cpu, MemoryBus& memory_bus, uint16_t address, Register load_register) {

    auto value = cpu.registers[load_register];

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t LD::to_address_from_value(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register, uint8_t value) {

    auto address = cpu.double_register(address_register);

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t LD::to_address_from_single(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register, Register load_register, Modifier modifier) {

    auto address = cpu.double_register(address_register);

    auto value = cpu.registers[load_register];

    memory_bus.write_to_memory(address, value);

    if(modifier == Inc) {
        INC::pair(cpu, address_register);
    } else {
        DEC::pair(cpu, address_register);
    }

    return cpu.pc() + 1;
}

uint16_t LD::double_from_value(CPU& cpu, DoubleRegister in_register, uint16_t value) {

    cpu.double_register(in_register, value);

    return cpu.pc() + 1;
}

uint16_t LD::double_from_double(CPU& cpu, DoubleRegister in_register, DoubleRegister from_register) {

    auto value = cpu.double_register(from_register);
    cpu.double_register(in_register, value);

    return cpu.pc() + 1;
}

uint16_t LD::double_from_double(CPU& cpu, DoubleRegister in_register, DoubleRegister from_register, int8_t adjuster) {

    auto value = cpu.double_register(from_register);
    value += adjuster;

    cpu.double_register(in_register, value);

    return cpu.pc() + 1;
}



uint16_t LDIO::to_io_single_from_single(CPU& cpu, MemoryBus& memory_bus, Register io_register, Register value_register) {

    auto io_register_value = cpu.registers[io_register];

    uint16_t address = 0xFF00 + io_register_value;

    auto value = cpu.registers[value_register];

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t to_io_address_from_single(CPU& cpu, MemoryBus& memory_bus, uint8_t io_address, Register value_register) {

    uint16_t address = 0xFF00 + io_address;

    auto value = cpu.registers[value_register];

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t to_single_from_io_address(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint8_t io_address) {

    uint16_t address = 0xFF00 + io_address;

    cpu.registers[in_register] = memory_bus.read_from_memory(address);

    return cpu.pc() + 1;
}

uint16_t to_single_from_io_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, Register io_register) {

    auto register_value = cpu.registers[io_register];

    uint16_t address = 0xFF00 + register_value;

    cpu.registers[in_register] = memory_bus.read_from_memory(address);

    return cpu.pc() + 1;
}
