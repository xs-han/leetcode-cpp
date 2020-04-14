//
// Created by xushen on 4/14/20.
//

#include <gtest/gtest.h>

#include "0041_first-missing-positive.h"

TEST(T_0041, SOLUTION) {
    Q_0041::Solution s;
//    std::vector<int> nums = {3,4,-1,1};
//    std::vector<int> nums = {1};
    std::vector<int> nums = {0,2,2,1,1};
    int res = s.firstMissingPositive(nums);
    std::cout << res;
}