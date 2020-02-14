//
// Created by xushen on 2/14/20.
//

#ifndef LEETCODE_CPP_0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H
#define LEETCODE_CPP_0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H

#include <vector>

namespace Q_0033 {
class Solution {
 public:
    int search(std::vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int low = 0, high = nums.size() - 1, mid = 0;
        while (low < high) {
            mid = (high + low) / 2;
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
        }
        return nums[low] == target ? low : -1;
    }
};
}

#endif //LEETCODE_CPP_0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H
