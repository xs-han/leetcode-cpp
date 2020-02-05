//
// Created by xushen on 2/5/20.
//

#include <gtest/gtest.h>

#include "0020_valid-parentheses.h"

TEST(T_0020, SOLUTION) {
    std::string str = "";
    Q_0020::Solution s;
    bool valid = s.isValid(str);
    if (valid) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
}