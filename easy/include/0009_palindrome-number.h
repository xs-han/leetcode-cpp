//
// Created by xushen on 2/8/20.
//

#ifndef LEETCODE_CPP_0009_PALINDROME_NUMBER_H
#define LEETCODE_CPP_0009_PALINDROME_NUMBER_H

namespace Q_0009 {

class Solution {
    const std::vector<int> pow10 = {
            1,
            10,
            100,
            1000,
            10000,
            100000,
            1000000,
            10000000,
            100000000,
            1000000000,
    };
 public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int y = x;
        int num_bit = 0;
        while (y > 0) {
            y /= 10;
            num_bit++;
        }
        if (num_bit < 2) {
            return true;
        }

        y = x;
        int half_num_bit = num_bit - num_bit / 2;
        do {
            int l = x % 10;
            int h = y / pow10[--num_bit];
            if (l != h) {
                return false;
            }
            x /= 10;
            y -= h * pow10[num_bit];
        } while (num_bit > half_num_bit);
        return true;
    }
};

class Solution2 {
 public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x % 10 == 0 && x != 0) {
            return false;
        }

        int y = 0, b = 0, x_pre = x;
        while (x > y) {
            b = x % 10;
            y = y * 10 + b;
            x_pre = x;
            x = x / 10;
        }
        return x == y || x_pre == y;
    }
};

}

#endif //LEETCODE_CPP_0009_PALINDROME_NUMBER_H
