#include <gtest/gtest.h>
#include <iostream>
#include <cstdint>

#include "increment.h"
#include "cpu.h"

// Single Register Tests

TEST(IncrementTest, IncrementSingleZeroResultsIsOne) {
    CPU cpu;
    
    INC::single(cpu, A);

    ASSERT_EQ(cpu.registers[A], 1);
}

TEST(IncrementTest, IncrementSingleThenDecrementIsZero) {
    CPU cpu;
    
    INC::single(cpu, A);
    DEC::single(cpu, A);

    ASSERT_EQ(cpu.registers[A], 0);
}

TEST(IncrementTest, IncrementDoubleThenDecrementIsZero) {
    CPU cpu;
    
    INC::pair(cpu, BC);
    DEC::pair(cpu, BC);

    uint16_t value = 0;

    ASSERT_EQ(cpu.bc(), value);
}

TEST(IncrementTest, SingleValueOverflowsAndSetsZeroFlag) {
    CPU cpu;

    cpu.registers[A] = 255;
    
    INC::single(cpu, A);

    ASSERT_EQ(cpu.registers[A], 0);
    ASSERT_EQ(cpu.flags[Zero], true);
}

TEST(IncrementTest, SingleHalfCarryIsSet) {
    CPU cpu;

    cpu.registers[A] = 15;
    
    INC::single(cpu, A);

    ASSERT_EQ(cpu.flags[Zero], false);
    ASSERT_EQ(cpu.flags[HalfCarry], true);
}

TEST(DecrementTest, DecrementFromOneResultsInZeroAndSetsZeroFlag) {
    CPU cpu;

    cpu.registers[A] = 1;
    
    DEC::single(cpu, A);

    ASSERT_EQ(cpu.registers[A], 0);
    ASSERT_EQ(cpu.flags[Zero], true);
}

TEST(DecrementTest, SingleHalfCarryIsSet) {
    CPU cpu;

    cpu.registers[A] = 16;
    
    DEC::single(cpu, A);

    ASSERT_EQ(cpu.flags[Zero], false);
    ASSERT_EQ(cpu.flags[HalfCarry], true);
}

// Double Register Tests

TEST(IncrementTest, IncrementDoubleZeroResultsIsOne) {
    CPU cpu;
    
    INC::pair(cpu, BC);

    uint16_t value = 1;

    ASSERT_EQ(cpu.bc(), value);
}

TEST(DecrementTest, IncrementDoubleZeroResultsIsOne) {
    CPU cpu;

    cpu.bc(1);
    
    DEC::pair(cpu, BC);

    uint16_t value = 0;

    ASSERT_EQ(cpu.bc(), value);
}

