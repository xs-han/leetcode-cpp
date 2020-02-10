//
// Created by xushen on 2/10/20.
//

#include <gtest/gtest.h>

#include "0028_implement-strstr.h"

TEST(T_0028, SOLUTION) {
    std::string haystack = "aa", needle = "aaa";
    Q_0028::Solution s;
    int n = s.strStr(haystack, needle);
    std::cout << n << std::endl;
}