//
// Created by xushen on 4/13/20.
//

#ifndef LEETCODE_CPP_0040_COMBINATION_SUM_II_H
#define LEETCODE_CPP_0040_COMBINATION_SUM_II_H

#include <vector>

namespace Q_0040 {
class Solution {
public:
    std::vector<std::vector<int>>& combinationSum2(
            std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> combination;
        p_end = candidates.end();
        DFS(candidates.begin(), target, combination);
        return res;
    }

private:
    std::vector<int>::iterator p_end;
    std::vector<std::vector<int>> res;
    void DFS(std::vector<int>::iterator start,
            int target, std::vector<int>& combination) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }

        while (start != p_end && *start <= target) {
            combination.push_back(*start);
            DFS(start + 1, target - *start, combination);
            int value = *start;
            while (start != p_end && *(start) == value) {
                start++;
            }
            combination.pop_back();
        }
    }
};
}

#endif //LEETCODE_CPP_0040_COMBINATION_SUM_II_H
