//
// Created by xushen on 2/10/20.
//

#include <gtest/gtest.h>

#include "0027_remove-element.h"

TEST(T_0027, SOLUTION) {
    Q_0027::Solution s;
    std::vector<int> v = {1};
    int n = s.removeElement(v, 1);
    std::cout << n << std::endl;
}