//
// Created by xushen on 2/12/20.
//

#include <gtest/gtest.h>

#include "0031_next-permutation.h"

TEST(T_0031, SOLUTION) {
    std::vector<int> nums = {1,5,1};
    Q_0031::Solution s;
    s.nextPermutation(nums);
    for (int i = 0; i < nums.size() - 1; i++) {
        std::cout << nums[i] << ", ";
    }
    std::cout << nums[nums.size() - 1] << std::endl;
}