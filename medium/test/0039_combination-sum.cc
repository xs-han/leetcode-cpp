//
// Created by xushen on 4/8/20.
//

#include <gtest/gtest.h>

#include "0039_combination-sum.h"

TEST(T_0039, SOLUTION) {
    Q_0039::Solution s;
    std::vector<int> candidates = {2,3,6,7};
    int target = 7;
    std::vector<std::vector<int>> res = s.combinationSum(candidates, target);
    for (const std::vector<int> c: res) {
        std::cout << "[";
        for (int n : c) {
            std::cout << n << ", ";
        }
        std::cout << "]" << std::endl;
    }
}