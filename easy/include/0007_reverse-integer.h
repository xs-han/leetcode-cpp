//
// Created by xushen on 2/7/20.
//

#ifndef LEETCODE_CPP_0007_REVERSE_INTEGER_H
#define LEETCODE_CPP_0007_REVERSE_INTEGER_H

namespace Q_0007 {
class Solution {
    constexpr static int kInt32MaxDiv10 = INT32_MAX / 10;
    constexpr static int kInt32MaxMod10 = INT32_MAX % 10;
    constexpr static int kInt32MinDiv10 = INT32_MIN / 10;
    constexpr static int kInt32MinMod10 = INT32_MIN % 10;
 public:
    int reverse(int x) {
        int y = 0;
        while (x != 0) {
            int b = x % 10;
            x = x / 10;
            if ((y < kInt32MinDiv10 || (y == kInt32MaxDiv10 && b > kInt32MinMod10)) ||
                    (y > kInt32MaxDiv10 || (y == kInt32MaxDiv10 && b > kInt32MaxMod10))) {
                return 0;
            }
            y = y * 10 + b;
        }
        return y;
    }
};
}

#endif //LEETCODE_CPP_0007_REVERSE_INTEGER_H
