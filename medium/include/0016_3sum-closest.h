//
// Created by xushen on 2/2/20.
//

#ifndef LEETCODE_CPP_0016_3SUM_CLOSEST_H
#define LEETCODE_CPP_0016_3SUM_CLOSEST_H

#include <vector>

namespace Q_0016 {
class Solution {
 public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::sort(nums.begin(), nums.end());

        int a = 0, b = 0, c = 0;
        int three_sum = 0, current_distance;
        int min_distance = INT32_MAX, closest_target = 0;
        for (int i = 0u; i < nums.size(); i++) {
            a = nums[i];
            int j = i + 1;
            int k = nums.size() - 1u;
            while (j < k) {
                b = nums[j];
                c = nums[k];
                three_sum = a + b + c;
                if (three_sum > target) {
                    k--;
                } else if (three_sum < target) {
                    j++;
                } else {
                    return target;
                }

                current_distance = std::abs(three_sum - target);
                if (current_distance < min_distance) {
                    min_distance = current_distance;
                    closest_target = three_sum;
                }
            }
        }
        return closest_target;
    }
};
}

#endif //LEETCODE_CPP_0016_3SUM_CLOSEST_H
