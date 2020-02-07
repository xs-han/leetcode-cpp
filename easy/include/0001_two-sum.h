//
// Created by xushen on 2/7/20.
//

#ifndef LEETCODE_CPP_0001_TWO_SUM_H
#define LEETCODE_CPP_0001_TWO_SUM_H

#include <vector>
#include <unordered_map>

namespace Q_0001 {
class Solution {
 public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> s(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            s[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto p = s.find(target - nums[i]);
            if (p != s.end() && p->second != i) {
                return {i, p->second};
            }
        }

        return std::vector<int>();
    }
};
}

#endif //LEETCODE_CPP_0001_TWO_SUM_H
