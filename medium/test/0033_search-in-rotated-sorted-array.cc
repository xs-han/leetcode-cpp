//
// Created by xushen on 2/14/20.
//

#include <gtest/gtest.h>

#include "0033_search-in-rotated-sorted-array.h"

TEST(T_0033, SOLUTION) {
    Q_0033::Solution s;
    std::vector<int> nums = {4,5,6,7,0,1,2};
    int target = 6;
    std::cout << s.search(nums, target) << std::endl;
}