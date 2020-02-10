//
// Created by xushen on 2/10/20.
//

#ifndef LEETCODE_CPP_0027_REMOVE_ELEMENT_H
#define LEETCODE_CPP_0027_REMOVE_ELEMENT_H

#include <vector>

namespace Q_0027 {

class Solution {
 public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        auto p_end = nums.end() - 1;
        auto p = nums.begin();
        while (p <= p_end) {
            if (*p == val) {
                std::swap(*p, *p_end);
                p_end--;
            } else {
                p++;
            }
        }
        return p_end - nums.begin() + 1;
    }
};

}

#endif //LEETCODE_CPP_0027_REMOVE_ELEMENT_H
