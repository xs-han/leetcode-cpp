//
// Created by xushen on 4/14/20.
//

#ifndef LEETCODE_CPP_0041_FIRST_MISSING_POSITIVE_H
#define LEETCODE_CPP_0041_FIRST_MISSING_POSITIVE_H

#include <vector>

namespace  Q_0041 {

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int length = nums.size();

        for (int& n : nums) {
            n = n <= 0 ? length + 1 : n;
        }
        for (size_t i = 0; i < nums.size(); i++) {
            int abs_n = std::abs(nums[i]);
            if (abs_n <= length && nums[abs_n - 1] > 0) {
                nums[abs_n - 1] = -nums[abs_n - 1];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return length + 1;
    }
};
}

#endif //LEETCODE_CPP_0041_FIRST_MISSING_POSITIVE_H
