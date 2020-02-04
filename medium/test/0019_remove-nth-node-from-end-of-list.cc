//
// Created by xushen on 2/4/20.
//

#include <gtest/gtest.h>

#include "0019_remove-nth-node-from-end-of-list.h"
#include <iostream>

TEST(T_0019, SOLUTION) {
    std::vector<int> data = {1,2,3,4,5};
    ListNode* head = GenerateList(data);
    std::cout << head << std::endl;
    Q_0019::Solution s;
    head = s.removeNthFromEnd(head, 4);
    std::cout << head << std::endl;
}