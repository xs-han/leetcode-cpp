//
// Created by xushen on 2/7/20.
//

#include <gtest/gtest.h>

#include "0014_longest-common-prefix.h"

TEST(T_0014, SOLUTION) {
    std::vector<std::string> strs1 = {"flower","flow","flight"};
    std::vector<std::string> strs2 = {"dog","racecar","car"};

    Q_0014::Solution s;
    std::cout << s.longestCommonPrefix(strs2) << std::endl;
}