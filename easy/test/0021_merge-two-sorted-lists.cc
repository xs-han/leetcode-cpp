//
// Created by xushen on 2/5/20.
//

#include <gtest/gtest.h>

#include "0021_merge-two-sorted-lists.h"

TEST(T_0021, SOLUTION) {
    ListNode* l1 = GenerateList({1,2,4});
    ListNode* l2 = GenerateList({1,3,4});

    Q_0021::Solution s;
    ListNode* r = s.mergeTwoLists(l1, l2);
    std::cout << r << std::endl;
}