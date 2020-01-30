//
// Created by xushen on 1/30/20.
//

#include <gtest/gtest.h>

#include "0011_container-with-most-water.h"

TEST(T_0011, SOLUTION) {
//    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::vector<int> height = {1, 1};
    Q_0011::Solution s;
    int area = s.maxArea(height);
    std::cout << area;
}