//
// Created by xushen on 1/28/20.
//

#ifndef LEETCODE_CPP_MEDIAN_OF_TWO_SORTED_ARRAYS_H
#define LEETCODE_CPP_MEDIAN_OF_TWO_SORTED_ARRAYS_H

#include <vector>

namespace Q_0004 {

class Solution {
 public:
    double findMedianSortedArrays(
            std::vector<int>& nums1,
            std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            std::swap(nums1, nums2);
        }

        size_t l1 = nums1.size();
        size_t l2 = nums2.size();
        size_t total_l = l1 + l2;
        size_t half_size = total_l >> 1u;

        if (l1 == 0) {
            if (l2 & 1u == 1u) {
                return nums2[half_size];
            } else {
                return (nums2[half_size] + nums2[half_size-1]) / 2.;
            }
        }

        size_t bar1 = l1 >> 1u;
        size_t bar2 = 0u;
        size_t bar1_low = 0;
        size_t bar1_high = l1 + 1;
        while (true) {
            bar2 = half_size - bar1;

            if (bar1 > 0 && bar2 < l2 && nums1[bar1-1] > nums2[bar2]) {
                bar1_high = bar1;
                bar1 = bar1_low + ((bar1 - bar1_low) >> 1u);
            } else if (bar2 > 0 && bar1 < l1 && nums2[bar2-1] > nums1[bar1]) {
                bar1_low = bar1;
                bar1 += (bar1_high + 1u - bar1) >> 1u;
            } else {
                if (total_l & 1u == 1u) {
                    if (bar1 >= l1) {
                        return nums2[bar2];
                    } else if (bar2 >= l2) {
                        return nums1[bar1];
                    } else {
                        return std::min(nums1[bar1], nums2[bar2]);
                    }
                } else {
                    int left_value = 0;
                    if (bar1 == 0) {
                        left_value = nums2[bar2-1];
                    } else if (bar2 == 0) {
                        left_value = nums1[bar1-1];
                    } else {
                        left_value = std::max(nums1[bar1-1], nums2[bar2-1]);
                    };
                    int right_value = 0;
                    if (bar1 >= l1) {
                        right_value = nums2[bar2];
                    } else if (bar2 >= l2) {
                        right_value = nums1[bar1];
                    } else {
                        right_value = std::min(nums1[bar1], nums2[bar2]);
                    }
                    return (left_value + right_value) / 2.;
                }
            }
        }
    }
};

}

#endif //LEETCODE_CPP_MEDIAN_OF_TWO_SORTED_ARRAYS_H
