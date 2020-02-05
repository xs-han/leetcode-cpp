//
// Created by xushen on 2/5/20.
//

#ifndef LEETCODE_CPP_0021_MERGE_TWO_SORTED_LISTS_H
#define LEETCODE_CPP_0021_MERGE_TWO_SORTED_LISTS_H

#include "linked_list.h"

namespace Q_0021 {

class Solution {
 public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        ListNode result(0);
        ListNode* head = &result;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        if (l1) {
            head->next = l1;
        } else {
            head->next = l2;
        }

        return result.next;
    }
};

class Solution2 {
 public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }

        ListNode* result = nullptr;
        if (l1->val < l2->val) {
            result = l1;
            l1 = l1->next;
        } else {
            result = l2;
            l2 = l2->next;
        }
        ListNode* head = result;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        if (l1 == nullptr) {
            head->next = l2;
        } else {
            head->next = l1;
        }

        return result;
    }
};

}

#endif //LEETCODE_CPP_0021_MERGE_TWO_SORTED_LISTS_H
