//
// Created by xushen on 1/28/20.
//

#include <gtest/gtest.h>

#include "0004_median-of-two-sorted-arrays.h"

TEST(T_0004, SOLUTION) {
    // Solution s;
//    std::vector<int> nums1 = {3,4};
//    std::vector<int> nums2 = {1,2};
//    std::vector<int> nums1 = {1,2,3,6,7};
//    std::vector<int> nums2 = {4,5,8,9,10};
    std::vector<int> nums1 = {2};
    std::vector<int> nums2 = {};
    Q_0004::Solution s;
    double r = s.findMedianSortedArrays(nums1, nums2);
    std::cout << r;
}
