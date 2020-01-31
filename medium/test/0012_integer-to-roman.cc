//
// Created by xushen on 1/31/20.
//

#include <gtest/gtest.h>

#include "0012_integer-to-roman.h"

TEST(T_0012, SOLUTION) {
    Q_0012::Solution s;
    std::string roamn = s.intToRoman(1394);
    std::cout << roamn;
}