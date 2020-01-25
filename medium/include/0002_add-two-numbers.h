//
// Created by xushen on 1/24/20.
//

#include "linked_list.h"

namespace Q_0002 {

class Solution {
 public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = l1;
        while (true) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            l1->val = sum % 10;
            if (!l1->next) {
                l1->next = l2->next;
                l2->next = nullptr;
                ManageCarry(l1, carry);
                return result;
            } else if (!l2->next) {
                ManageCarry(l1, carry);
                return result;
            } else {
                l1 = l1->next;
                l2 = l2->next;
            }
        }
    }

    void ManageCarry(ListNode* l1, int carry) {
        while (carry) {
            if (l1->next == nullptr) {
                l1->next = new ListNode(0);
            }
            int sum = l1->next->val + carry;
            carry = sum / 10;
            l1->next->val = sum % 10;
            l1 = l1->next;
        }
    }
};

}