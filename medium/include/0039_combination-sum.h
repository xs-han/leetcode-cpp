//
// Created by xushen on 4/8/20.
//

#ifndef LEETCODE_CPP_0039_COMBINATION_SUM_H
#define LEETCODE_CPP_0039_COMBINATION_SUM_H

namespace Q_0039 {
class Solution {
public:
    std::vector<std::vector<int> > res;
    std::vector<int>::iterator p_end;
    std::vector<std::vector<int> > combinationSum(
            std::vector<int> &candidates,
            int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> combination;
        p_end = candidates.end();
        DFS(candidates.begin(), target, combination);
        return res;
    }

private:
    void DFS(const std::vector<int>::iterator p_candidate,
            int target,
            std::vector<int>& combination) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }

        std::vector<int>::iterator start = p_candidate;
        while (start != p_end && *start <= target) {
            combination.push_back(*start);
            DFS(start, target - *start, combination);
            combination.pop_back();
            start++;
        }
    }
};
}

#endif //LEETCODE_CPP_0039_COMBINATION_SUM_H
