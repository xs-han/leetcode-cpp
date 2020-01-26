//
// Created by xushen on 1/26/20.
//

#include <gtest/gtest.h>

#include "0005_longest-palindromic-substring.h"

TEST(T_0005, SOLUTION) {
    // Solution s;
    Q_0005::Solution s;
    std::string r = s.longestPalindrome(std::string("babad"));
    std::cout << r;
}