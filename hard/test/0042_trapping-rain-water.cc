//
// Created by xushen on 4/16/20.
//

#include <gtest/gtest.h>

#include "0042_trapping-rain-water.h"

TEST(T_0042, SOLUTION) {
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Q_0042::Solution s;
    int res = s.trap(height);
    std::cout << res;
}