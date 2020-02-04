//
// Created by xushen on 2/4/20.
//

#ifndef LEETCODE_CPP_0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define LEETCODE_CPP_0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H

#include <linked_list.h>

#include <list>

namespace Q_0019 {

class Solution {
 public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result = head;
        std::list<ListNode*> node_window;
        for (int i = 0; i < n; i++) {
            node_window.push_back(head);
            head = head->next;
        }
        if (head == nullptr) {
            ListNode* p_del = result;
            result = result->next;
            delete(p_del);
            return result;
        }
        while (head->next != nullptr) {
            node_window.push_back(head);
            node_window.pop_front();
            head = head->next;
        }
        ListNode* p_del_pre = node_window.front();
        ListNode* p_del = p_del_pre->next;
        p_del_pre->next = p_del->next;
        delete p_del;
        return result;
    }
};

class Solution2 {
 public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result = head;
        ListNode* node_window_start = head;
        for (int i = 0; i < n; i++) {
            head = head->next;
        }
        if (head == nullptr) {
            ListNode* p_del = result;
            result = result->next;
            delete(p_del);
            return result;
        }
        while (head->next != nullptr) {
            node_window_start = node_window_start->next;
            head = head->next;
        }
        ListNode* p_del_pre = node_window_start;
        ListNode* p_del = p_del_pre->next;
        p_del_pre->next = p_del->next;
        delete p_del;
        return result;
    }
};

}

#endif //LEETCODE_CPP_0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
