//
// Created by xushen on 1/31/20.
//

#include <gtest/gtest.h>

#include "0013_roman-to-integer.h"

TEST(T_0013, SOLUTION) {
    Q_0013::Solution s;
    int n = s.romanToInt("MCMXCIV");
    EXPECT_EQ(n, 1994);
}