//
// Created by xushen on 1/30/20.
//

#ifndef LEETCODE_CPP_0011_CONTAINER_WITH_MOST_WATER_H
#define LEETCODE_CPP_0011_CONTAINER_WITH_MOST_WATER_H

#include <vector>
#include <iostream>

namespace Q_0011 {

class Solution {
 public:
    int maxArea(const std::vector<int>& height) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        size_t left_bar = 0;
        size_t right_bar = height.size() - 1;
        size_t width = right_bar;
        bool flag = height[left_bar] > height[right_bar];
        size_t area = (flag ? height[right_bar] : height[left_bar]) * width;
        size_t max_area = area;

        while (width > 1) {
            if (flag) {
                right_bar--;
            } else {
                left_bar++;
            }
            flag = height[left_bar] > height[right_bar];
            area = (flag ? height[right_bar] : height[left_bar]) * (--width);
            if (area > max_area) {
                max_area = area;
            }
        }

        return max_area;
    }
};

}

#endif //LEETCODE_CPP_0011_CONTAINER_WITH_MOST_WATER_H
