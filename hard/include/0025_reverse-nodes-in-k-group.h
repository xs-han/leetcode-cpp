//
// Created by xushen on 2/9/20.
//

#ifndef LEETCODE_CPP_0025_REVERSE_NODES_IN_K_GROUP_H
#define LEETCODE_CPP_0025_REVERSE_NODES_IN_K_GROUP_H

#include "linked_list.h"

namespace Q_0025 {

class Solution {
 public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode result(0);
        ListNode *ahead = &result;
        if (head == nullptr) {
            return nullptr;
        }
        ahead->next = head;
        std::vector<ListNode*> period(k);

        while (head) {
            for (int i = 0; i < k; i++) {
                if (!head) {
                    return result.next;
                }
                period[i] = head;
                head = head->next;
            }

            size_t i = k-1;
            head = period[i]->next;
            while (i > 0u) {
                period[i]->next = period[i-1];
                i--;
            }
            period[0]->next = head;
            ahead->next = period[k-1];
            ahead = period[0];
        }
        return result.next;
    }
};

class Solution2 {
 public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode result(0);
        ListNode *ahead = &result;
        if (head == nullptr) {
            return nullptr;
        }
        ahead->next = head;
        std::vector<ListNode*> period(k);

        while (head) {
            for (int i = 0; i < k; i++) {
                if (!head) {
                    return result.next;
                }
                period[i] = head;
                head = head->next;
            }

            for (int i = k-1; i >= 0; i--) {
                ahead->next = period[i];
                ahead = ahead->next;
            }
            ahead->next = head;
        }
        return result.next;
    }
};

}

#endif //LEETCODE_CPP_0025_REVERSE_NODES_IN_K_GROUP_H
