#include <gtest/gtest.h>
#include <iostream>
#include <cstdint>

#include "increment.h"
#include "cpu.h"

// Single Register Tests

TEST(IncrementTest, IncrementSingleZeroResultsIsOne) {
    CPU cpu;
    
    INC::single(cpu, "a");

    ASSERT_EQ(cpu.registers["a"], 1);
}

TEST(IncrementTest, IncrementSingleThenDecrementIsZero) {
    CPU cpu;
    
    INC::single(cpu, "a");
    DEC::single(cpu, "a");

    ASSERT_EQ(cpu.registers["a"], 0);
}

TEST(IncrementTest, IncrementDoubleThenDecrementIsZero) {
    CPU cpu;
    
    INC::pair(cpu, "bc");
    DEC::pair(cpu, "bc");

    uint16_t value = 0;

    ASSERT_EQ(cpu.bc(), value);
}

TEST(IncrementTest, SingleValueOverflowsAndSetsZeroFlag) {
    CPU cpu;

    cpu.registers["a"] = 255;
    
    INC::single(cpu, "a");

    ASSERT_EQ(cpu.registers["a"], 0);
    ASSERT_EQ(cpu.flags["z"], true);
}

TEST(IncrementTest, SingleHalfCarryIsSet) {
    CPU cpu;

    cpu.registers["a"] = 15;
    
    INC::single(cpu, "a");

    ASSERT_EQ(cpu.flags["z"], false);
    ASSERT_EQ(cpu.flags["h"], true);
}

TEST(DecrementTest, DecrementFromOneResultsInZeroAndSetsZeroFlag) {
    CPU cpu;

    cpu.registers["a"] = 1;
    
    DEC::single(cpu, "a");

    ASSERT_EQ(cpu.registers["a"], 0);
    ASSERT_EQ(cpu.flags["z"], true);
}

TEST(DecrementTest, SingleHalfCarryIsSet) {
    CPU cpu;

    cpu.registers["a"] = 16;
    
    DEC::single(cpu, "a");

    ASSERT_EQ(cpu.flags["z"], false);
    ASSERT_EQ(cpu.flags["h"], true);
}

// Double Register Tests

TEST(IncrementTest, IncrementDoubleZeroResultsIsOne) {
    CPU cpu;
    
    INC::pair(cpu, "bc");

    uint16_t value = 1;

    ASSERT_EQ(cpu.bc(), value);
}

TEST(DecrementTest, IncrementDoubleZeroResultsIsOne) {
    CPU cpu;

    cpu.bc(1);
    
    DEC::pair(cpu, "bc");

    uint16_t value = 0;

    ASSERT_EQ(cpu.bc(), value);
}

