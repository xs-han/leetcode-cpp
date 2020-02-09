//
// Created by xushen on 2/9/20.
//

#include <gtest/gtest.h>

#include "0026_remove-duplicates-from-sorted-array.h"

TEST(T_0026, SOLUTION) {
    std::vector<int> v = {1,1,2,2,3,3,3,3,3};
    Q_0026::Solution s;
    int n = s.removeDuplicates(v);
    for (int i = 0; i < n-1; i++) {
        std::cout << v[i] << ", ";
    }
    if (n > 0) {
        std::cout << v[n - 1] << std::endl;
    }
}