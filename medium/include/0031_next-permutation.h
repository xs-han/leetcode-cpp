//
// Created by xushen on 2/12/20.
//

#ifndef LEETCODE_CPP_0031_NEXT_PERMUTATION_H
#define LEETCODE_CPP_0031_NEXT_PERMUTATION_H

#include <vector>

namespace Q_0031 {

class Solution {
 public:
    void nextPermutation(std::vector<int>& nums) {
        if (nums.empty()) {
            return;
        }

        auto p = nums.end() - 1;
        while (p != nums.begin() && *(p-1) >= *p) {
            p--;
        }
        if (p == nums.begin()) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        auto q = p + 1;
        int& m = *(p-1);
        for (; q != nums.end(); q++) {
            if (*q <= m) {
                std::swap(m, *(q-1));
                std::reverse(p, nums.end());
                return;
            }
        }
        std::swap(m, nums.back());
        std::reverse(p, nums.end());
    }
};

}

#endif //LEETCODE_CPP_0031_NEXT_PERMUTATION_H
