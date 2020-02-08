//
// Created by xushen on 2/8/20.
//

#ifndef LEETCODE_CPP_0024_SWAP_NODES_IN_PAIRS_H
#define LEETCODE_CPP_0024_SWAP_NODES_IN_PAIRS_H

#include "linked_list.h"

namespace Q_0024 {
class Solution {
 public:
    ListNode* swapPairs(ListNode* head) {
        ListNode result(0);
        ListNode* first = &result;
        first->next = head;
        ListNode* tail = nullptr;
        while (first->next) {
            head = first->next;
            tail = head->next;
            if (!tail) {
                return result.next;
            }
            first->next = tail;
            head->next = tail->next;
            tail->next = head;
            first = head;
        }
        return result.next;
    }
};
}

#endif //LEETCODE_CPP_0024_SWAP_NODES_IN_PAIRS_H
