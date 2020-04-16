//
// Created by xushen on 4/16/20.
//

#ifndef LEETCODE_CPP_0042_TRAPPING_RAIN_WATER_H
#define LEETCODE_CPP_0042_TRAPPING_RAIN_WATER_H

#include <vector>

namespace Q_0043 {
class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        const int* p_left = &height[0];
        const int* p_right = &height.back();
        int left_max = 0, right_max = 0;
        int sum = 0;
        while (p_left < p_right) {
            left_max = std::max(*p_left, left_max);
            right_max = std::max(*p_right, right_max);
            if (left_max < right_max) {
                sum += left_max - *(p_left++);
            } else {
                sum += right_max - *(p_right--);
            }
        }
        return sum;
    }
};
}

#endif //LEETCODE_CPP_0042_TRAPPING_RAIN_WATER_H
