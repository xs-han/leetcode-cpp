//
// Created by xushen on 2/1/20.
//

#include <gtest/gtest.h>

#include "0015_3sum.h"

TEST(T_0015, SOLUTION) {
    Q_0015::Solution2 s;
//    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
//    std::vector<int> nums = {0, 0, 0};
    std::vector<int> nums = {0,-4,-1,-4,-2,-3,2};
    std::vector<std::vector<int>> result = s.threeSum(nums);
    std::cout << "[" << std::endl;
    for (const std::vector<int>& r : result) {
        if (r.size() < 3) {
            continue;
        }
        std::cout << "[" << r[0] << ", " << r[1] << ", " << r[2] << "]," << std::endl;
    }
    std::cout << "]" << std::endl;
}