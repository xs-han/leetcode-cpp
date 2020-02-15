//
// Created by xushen on 2/15/20.
//

#ifndef LEETCODE_CPP_0035_SEARCH_INSERT_POSITION_H
#define LEETCODE_CPP_0035_SEARCH_INSERT_POSITION_H

#include <vector>

namespace Q_0035 {
class Solution {
 public:
    int searchInsert(std::vector<int>& nums, int target) {
        auto low = nums.begin(), high = nums.end() - 1;
        while (low <= high) {
            auto mid = low + (high - low) / 2;
            if (*mid < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low - nums.begin();
    }
};
}

#endif //LEETCODE_CPP_0035_SEARCH_INSERT_POSITION_H
