//
// Created by xushen on 2/5/20.
//

#include <gtest/gtest.h>

#include "0022_generate-parentheses.h"

TEST(T_0022, SOLUTION) {
    Q_0022::Solution s;
    std::vector<std::string> result = s.generateParenthesis(3);
    std::cout << "[" << std::endl;
    for (const std::string& s : result) {
        std::cout << s << std::endl;
    }
    std::cout << "]" << std::endl;
}