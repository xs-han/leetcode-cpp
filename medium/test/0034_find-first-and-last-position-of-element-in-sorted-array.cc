//
// Created by xushen on 2/15/20.
//

#include <gtest/gtest.h>

#include "0034_find-first-and-last-position-of-element-in-sorted-array.h"

TEST(T_0034, SOLUTION) {
    std::vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Q_0034::Solution s;
    std::vector<int> res = s.searchRange(nums, target);
    std::cout << res[0] << ", " << res[1] << std::endl;
}