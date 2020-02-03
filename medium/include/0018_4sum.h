//
// Created by xushen on 2/3/20.
//

#ifndef LEETCODE_CPP_0018_4SUM_H
#define LEETCODE_CPP_0018_4SUM_H

#include <iostream>
#include <vector>

namespace Q_0018 {
class Solution {
    std::vector<std::vector<int>> result;
 public:
    std::vector<std::vector<int>>& fourSum(std::vector<int>& nums, int target) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        result.clear();
        if (nums.size() < 4) {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            int a = nums[i];
            if (i > 0 && nums[i-1] == a) {
                continue;
            }
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            if (nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) {
                continue;
            }

            for (int j = i+1; j < n - 2; j++) {
                int b = nums[j];
                if (j > i+1 && nums[j - 1] == b) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                    break;
                }
                if (nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) {
                    continue;
                }

                int k = j+1;
                int l = nums.size() - 1;
                int expected = target - a - b;
                while (k < l) {
                    int c = nums[k], d = nums[l];
                    if (c + d > expected) {
                        while (k < l && nums[--l] == d);
                    } else if (c + d < expected) {
                        while (k < l && nums[++k] == c);
                    } else {
                        result.push_back({a, b, c, d});
                        while (k < l && nums[--l] == d);
                        while (k < l && nums[++k] == c);
                    }
                }
            }
        }
        return result;
    }
};
}

#endif //LEETCODE_CPP_0018_4SUM_H
