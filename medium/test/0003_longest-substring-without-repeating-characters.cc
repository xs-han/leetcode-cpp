//
// Created by xushen on 1/25/20.
//

#include <gtest/gtest.h>

#include "0003_longest-substring-without-repeating-characters.h"

TEST(T_0003, SOLUTION) {
    // Solution s;
    Q_0003::SolutionFast s;
    int l = s.lengthOfLongestSubstring("aabaab!bb");
    EXPECT_EQ(l, 3);
}