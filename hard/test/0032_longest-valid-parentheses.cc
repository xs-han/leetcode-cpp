//
// Created by xushen on 2/14/20.
//

#include <gtest/gtest.h>

#include "0032_longest-valid-parentheses.h"

TEST(T_0032, SOLUTION) {
    std::string s = "()((())";
    Q_0032::Solution solution;
    std::cout << solution.longestValidParentheses(s) << std::endl;
}