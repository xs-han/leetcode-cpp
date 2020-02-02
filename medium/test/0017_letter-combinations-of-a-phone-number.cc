//
// Created by xushen on 2/2/20.
//

#include <gtest/gtest.h>

#include "0017_letter-combinations-of-a-phone-number.h"

TEST(T_0017, SOLUTION) {
    Q_0017::Solution s;
    Q_0017::Solution2 s2;
    std::vector<std::string> result = s2.letterCombinations("234");
    for (const std::string& str: result) {
        std::cout << str << std::endl;
    }
}