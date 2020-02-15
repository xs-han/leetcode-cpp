//
// Created by xushen on 2/15/20.
//

#include <gtest/gtest.h>

#include "0035_search-insert-position.h"

TEST(T_0035, SOLUTION) {
    std::vector<int> nums = {1,3,5,6};
    int target = 2;
    Q_0035::Solution s;
    std::cout << s.searchInsert(nums, target) << std::endl;
}