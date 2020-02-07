//
// Created by xushen on 2/7/20.
//

#include "0001_two-sum.h"

#include <gtest/gtest.h>

TEST(T_0001, SOLUTION) {
    std::vector<int> nums = {3,2,4};
    int target = 6;
    Q_0001::Solution s;
    std::vector<int> result = s.twoSum(nums, target);
    std::cout << result[0] << ", " << result[1] << std::endl;
}