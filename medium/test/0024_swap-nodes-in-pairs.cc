//
// Created by xushen on 2/8/20.
//

#include <gtest/gtest.h>

#include "0024_swap-nodes-in-pairs.h"

TEST(T_0024, SOLUTION) {
    Q_0024::Solution s;
    ListNode* a = GenerateList({1,2,3,4});
    std::cout << s.swapPairs(a) << std::endl;
}