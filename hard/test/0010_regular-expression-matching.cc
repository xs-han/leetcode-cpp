//
// Created by xushen on 1/28/20.
//

#include <gtest/gtest.h>
#include <string>

#include "0010_regular-expression-matching.h"

TEST(T_0010, SOLUTION) {
    Q_0010::Solution solution;

    std::string s = "";
    std::string p = "bab";
    bool r = solution.isMatch(s, p);
    std::cout << r;
}
