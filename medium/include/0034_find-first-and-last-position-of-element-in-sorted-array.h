//
// Created by xushen on 2/15/20.
//

#ifndef LEETCODE_CPP_0034_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
#define LEETCODE_CPP_0034_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H

namespace Q_0034 {
class Solution {
 public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto p = std::lower_bound(nums.begin(), nums.end(), target);
        if (p == nums.end() || *p != target) {
            return {-1, -1};
        }
        auto q = p+1;
        while (q != nums.end() && *q == *p) {
            q++;
        }
        return {static_cast<int>(p - nums.begin()),
                static_cast<int>(q - 1 - nums.begin())};
    }
};
}

#endif //LEETCODE_CPP_0034_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
