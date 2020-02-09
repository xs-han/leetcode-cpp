//
// Created by xushen on 2/9/20.
//

#ifndef LEETCODE_CPP_0026_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define LEETCODE_CPP_0026_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H

#include <vector>

namespace Q_0026 {
class Solution {
 public:
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }

    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        auto p_b = nums.begin();
        int b = *p_b;
        int n = nums.size();
        for (auto p = nums.begin()+1; p != nums.end(); p++) {
            if (*p == b) {
                n--;
                continue;
            } else {
                p_b++;
                b = *p;
                *p_b = b;
            }
        }
        nums.resize(n);
        return n;
    }
};
}

#endif //LEETCODE_CPP_0026_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
