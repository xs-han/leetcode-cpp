//
// Created by xushen on 2/7/20.
//

#include <gtest/gtest.h>

#include "0023_merge-k-sorted-lists.h"

TEST(T_0023, SOLUTION) {
    Q_0023::Solution s;

    ListNode* a = GenerateList({1,4,5});
    ListNode* b = GenerateList({1,3,4});
    ListNode* c = GenerateList({2,6});
    ListNode* d = GenerateList({});

    std::vector<ListNode*> lists = {a,b,c,d};
    ListNode* result = s.mergeKLists(lists);
    std::cout << result << std::endl;
}
