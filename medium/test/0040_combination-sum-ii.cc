//
// Created by xushen on 4/13/20.
//

#include <gtest/gtest.h>

#include "0040_combination-sum-ii.h"

TEST(T_0040, SOLUTION) {
    Q_0040::Solution s;
//    std::vector<int> candidates = {10,1,2,7,6,1,5};
    std::vector<int> candidates = {2,5,2,1,2};
//    int target = 8;
    int target = 5;
    std::vector<std::vector<int>> res = s.combinationSum2(candidates, target);
    for (const std::vector<int> c: res) {
        std::cout << "[";
        for (int n : c) {
            std::cout << n << ", ";
        }
        std::cout << "]" << std::endl;
    }
}