#include <gtest/gtest.h>
#include <iostream>

#include "cpu.h"
#include "memory_bus.h"
#include "stack.h"

// Pop Tests

TEST(PopTest, PoppedValueIsInMemory) {
    CPU cpu;
    MemoryBus memory_bus;

    uint16_t address = 65534;
    uint8_t value = 35;

    cpu.sp(address);
    cpu.bc(value);

    POP::register_pair(cpu, memory_bus, B, C);

    ASSERT_EQ(memory_bus.read_from_memory(address - 1), cpu.registers[B]);
    ASSERT_EQ(memory_bus.read_from_memory(address - 2), cpu.registers[C]);
}

TEST(PopTest, PopingDecrementsStackPointer) {
    CPU cpu;
    MemoryBus memory_bus;

    uint16_t address = 65534;
    uint8_t value = 35;

    cpu.sp(address);
    cpu.bc(value);

    POP::register_pair(cpu, memory_bus, B, C);

    ASSERT_EQ(cpu.sp(), address - 2);
}

// Push Tests

TEST(PushTest, PushedValueIsInRegisters) {
    CPU cpu;
    MemoryBus memory_bus;

    uint16_t address = 65534;
    uint8_t value = 35;

    cpu.sp(address);
    cpu.bc(value);

    POP::register_pair(cpu, memory_bus, B, C);

    PUSH::register_pair(cpu, memory_bus, H, L);

    ASSERT_EQ(cpu.hl(), value);
}

TEST(PushTest, PushingIncrementsStackPointer) {
    CPU cpu;
    MemoryBus memory_bus;

    uint16_t address = 65534;
    uint8_t value = 35;

    cpu.sp(address);
    cpu.bc(value);

    POP::register_pair(cpu, memory_bus, B, C);

    PUSH::register_pair(cpu, memory_bus, H, L);

    ASSERT_EQ(cpu.sp(), address);
}