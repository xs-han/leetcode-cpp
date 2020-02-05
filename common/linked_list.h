//
// Created by xushen on 1/24/20.
//

#ifndef LEETCODE_CPP_LINKED_LIST_H
#define LEETCODE_CPP_LINKED_LIST_H

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* GenerateList(const std::vector<int> data);

void DeleteList(ListNode* list);

std::ostream& operator << (std::ostream& stream, ListNode* head);


#endif //LEETCODE_CPP_LINKED_LIST_H
