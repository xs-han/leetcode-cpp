//
// Created by xushen on 1/24/20.
//

#include <iostream>
#include <vector>

#include "linked_list.h"

ListNode* GenerateList(const std::vector<int> data) {
    if (data.empty()) {
        return nullptr;
    }
    ListNode* result = new ListNode(data[0]);
    ListNode* p_new = result;
    for (int i = 1u; i < data.size(); i++) {
        p_new->next = new ListNode(data[i]);
        p_new = p_new->next;
    }
    return result;
}

void DeleteList(ListNode* list) {
    while (list != nullptr) {
        ListNode* p_del = list;
        list = list->next;
        delete(p_del);
    }
}

std::ostream& operator << (std::ostream& stream, ListNode* head) {
    while (head != nullptr) {
        stream << head->val;
        if (head->next != nullptr) {
            stream << ", ";
        }
        head = head->next;
    }
    return stream;
}
