#include <gtest/gtest.h>
#include <iostream>

#include "increment.h"
#include "cpu.h"

TEST(IncrementTest, IncrementingZeroResultsInOne) {
    CPU cpu;
    
    INC::single(cpu, "a");

    ASSERT_EQ(cpu.registers["a"], 1);
}

TEST(IncrementTest, IncrementThenDecrementIsZero) {
    CPU cpu;
    
    INC::single(cpu, "a");
    DEC::single(cpu, "a");

    ASSERT_EQ(cpu.registers["a"], 0);
}

