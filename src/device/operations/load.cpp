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

uint16_t LD::single_from_value(CPU& cpu, MemoryBus& memory_bus, Register in_register) {

    uint8_t value = memory_bus.get_next_in_memory(cpu);

    cpu.registers[in_register] = value;

    return cpu.pc() + 1;
}

uint16_t LD::to_address_from_single(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register, Register load_register) {

    auto address = cpu.double_register(address_register);

    auto value = cpu.registers[load_register];

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t LD::to_address_from_single(CPU& cpu, MemoryBus& memory_bus, Register load_register) {

    uint8_t right_half = memory_bus.get_next_in_memory(cpu);
    uint8_t left_half = memory_bus.get_next_in_memory(cpu);

    uint16_t address = left_half | right_half << 8;

    auto value = cpu.registers[load_register];

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t LD::to_address_from_value(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register) {

    uint8_t value = memory_bus.get_next_in_memory(cpu);

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

uint16_t LD::double_from_value(CPU& cpu, MemoryBus& memory_bus, DoubleRegister in_register) {

    uint8_t right_half = memory_bus.get_next_in_memory(cpu);
    uint8_t left_half = memory_bus.get_next_in_memory(cpu);

    uint16_t value = left_half | right_half << 8;

    cpu.double_register(in_register, value);

    return cpu.pc() + 1;
}

uint16_t LD::double_from_double(CPU& cpu, DoubleRegister in_register, DoubleRegister from_register) {

    auto value = cpu.double_register(from_register);
    cpu.double_register(in_register, value);

    return cpu.pc() + 1;
}

uint16_t LD::double_from_double(CPU& cpu, MemoryBus& memory_bus, DoubleRegister in_register, DoubleRegister from_register) {

    auto value = cpu.double_register(from_register);
    value += memory_bus.get_next_in_memory(cpu);

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

uint16_t LDIO::to_io_address_from_single(CPU& cpu, MemoryBus& memory_bus, Register value_register) {

    auto io_address = memory_bus.get_next_in_memory(cpu);

    uint16_t address = 0xFF00 + io_address;

    auto value = cpu.registers[value_register];

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t LDIO::to_single_from_io_address(CPU& cpu, MemoryBus& memory_bus, Register in_register) {

    auto io_address = memory_bus.get_next_in_memory(cpu);

    uint16_t address = 0xFF00 + io_address;

    cpu.registers[in_register] = memory_bus.read_from_memory(address);

    return cpu.pc() + 1;
}

uint16_t LDIO::to_single_from_io_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, Register io_register) {

    auto register_value = cpu.registers[io_register];

    uint16_t address = 0xFF00 + register_value;

    cpu.registers[in_register] = memory_bus.read_from_memory(address);

    return cpu.pc() + 1;
}
