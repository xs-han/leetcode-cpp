//
// Created by xushen on 2/7/20.
//

#ifndef LEETCODE_CPP_0023_MERGE_K_SORTED_LISTS_H
#define LEETCODE_CPP_0023_MERGE_K_SORTED_LISTS_H

#include <vector>
#include <queue>

#include "linked_list.h"

namespace Q_0023 {
class Solution {
 public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        size_t i = 0;
        size_t num_valid_lists = lists.size();
        while (i < num_valid_lists) {
            if (lists[i] == nullptr) {
                std::swap(lists[i], lists[--num_valid_lists]);
            } else {
                i++;
            }
        }
        if (num_valid_lists == 0) {
            return nullptr;
        }

        while (num_valid_lists > 1) {
            for (i = 0; i < num_valid_lists / 2; i++) {
                lists[i] = mergeTwoLists(lists[i * 2], lists[i*2+1]);
            }
            if (num_valid_lists % 2) {
                lists[(num_valid_lists - 1) / 2] = lists[num_valid_lists - 1];
            }
            num_valid_lists = num_valid_lists / 2 + num_valid_lists % 2;
        }

        return lists[0];
    }

 private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        bool all_empty = true;
        for (ListNode* p : lists) {
            if (p != nullptr) {
                all_empty = false;
            }
        }
        if (all_empty) {
            return nullptr;
        }

        size_t num_valid_lists = lists.size();
        ListNode result(0);
        ListNode* head = &result;

        auto cmp = [](const ListNode* p1, const ListNode* p2) {
            return p1->val > p2->val;
        };
        std::priority_queue<
                ListNode*, std::vector<ListNode*>, decltype(cmp)> min_heap(cmp);
        size_t i = 0;
        while (i < num_valid_lists) {
            if (lists[i] == nullptr) {
                std::swap(lists[i], lists[--num_valid_lists]);
            } else {
                i++;
            }
        }
        for (i = 0; i < num_valid_lists; i++) {
            min_heap.push(lists[i]);
        }

        while (num_valid_lists > 1u) {
            ListNode* t = min_heap.top();
            head->next = t;
            head = head->next;
            t = t->next;
            if (t != nullptr) {
                min_heap.push(t);
            } else {
                num_valid_lists--;
            }
            min_heap.pop();
        }
        head->next = min_heap.top();
        return result.next;
    }
};

class Solution3 {
 public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        bool all_empty = true;
        for (ListNode* p : lists) {
            if (p != nullptr) {
                all_empty = false;
            }
        }
        if (all_empty) {
            return nullptr;
        }

        size_t num_valid_lists = lists.size();
        ListNode result(0);
        ListNode* head = &result;

        while (num_valid_lists > 1u) {
            size_t i = 0;
            int min_value = INT32_MAX;
            size_t min_id = -1;

            while (i < num_valid_lists) {
                if (lists[i] == nullptr) {
                    std::swap(lists[i], lists[--num_valid_lists]);
                } else {
                    i++;
                }
            }
            for (i = 0u; i < num_valid_lists; i++) {
                if (lists[i]->val < min_value) {
                    min_id = i;
                    min_value = lists[i]->val;
                }
            }
            head->next = lists[min_id];
            lists[min_id] = lists[min_id]->next;
            head = head->next;
        }
        head->next = lists[0];
        return result.next;
    }
};

}

#endif //LEETCODE_CPP_0023_MERGE_K_SORTED_LISTS_H
