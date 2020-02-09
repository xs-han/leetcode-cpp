//
// Created by xushen on 2/9/20.
//

#include <gtest/gtest.h>

#include "0025_reverse-nodes-in-k-group.h"

TEST(T_0025, SOLUTION) {
    ListNode* a = GenerateList({1,2,3,4,5});
    Q_0025::Solution s;
    std::cout << s.reverseKGroup(a, 2) << std::endl;
}
