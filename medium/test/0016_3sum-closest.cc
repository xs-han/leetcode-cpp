//
// Created by xushen on 2/2/20.
//

#include <gtest/gtest.h>

#include "0016_3sum-closest.h"

TEST(T_0016, SOLUTION) {
    Q_0016::Solution s;
//    std::vector<int> nums = {-1, 2, 1, -4};
//    std::vector<int> nums = {0, 1, 2};
    std::vector<int> nums = {-1, 0, 1, 1, 55};
    int target = 3;
    int closest_target = s.threeSumClosest(nums, target);
    std::cout << closest_target << std::endl;
}