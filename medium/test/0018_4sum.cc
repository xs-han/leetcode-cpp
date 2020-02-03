//
// Created by xushen on 2/3/20.
//

#include <gtest/gtest.h>

#include "0018_4sum.h"

TEST(T_0018, SOLUTION) {
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
//    std::vector<int> nums = {0, 0, 0, 0};
    int target = 0;
    Q_0018::Solution s;
    std::vector<std::vector<int>> result = s.fourSum(nums, target);
    std::cout << "[" << std::endl;
    for (const std::vector<int>& r : result) {
        if (r.size() < 4) {
            continue;
        }
        std::cout << "[" << r[0] << ", " << r[1] << ", " << r[2] << ", " << r[3] << "]," << std::endl;
    }
    std::cout << "]" << std::endl;
}