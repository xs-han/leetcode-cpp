//
// Created by xushen on 1/26/20.
//

#ifndef LEETCODE_CPP_0005_LONGEST_PALINDROMIC_SUBSTRING_H
#define LEETCODE_CPP_0005_LONGEST_PALINDROMIC_SUBSTRING_H

#include <string>

namespace Q_0005 {
class Solution {
 public:
    std::string longestPalindrome(std::string s) {
        std::string manacher_str((s.length() << 1) + 3, '#');
        std::vector<size_t> palindromic_length(s.length() * 2 + 3);
        manacher_str[0] = '$';
        for (size_t i = 0; i < s.length(); i++) {
            manacher_str[(i << 1) + 2] = s[i];
        }
        manacher_str[(s.length() << 1) + 2] = '^';

        size_t center_id = 0;
        size_t mx = 0;
        size_t max_length = 0;
        size_t max_center = 0;

        for (size_t i = 1; i < manacher_str.length(); i++) {
            if (i < mx) {
                palindromic_length[i] = std::min(palindromic_length[(center_id << 1) - i], mx - i);
            } else {
                palindromic_length[i] = 1;
            }

            while (manacher_str[i + palindromic_length[i]] == manacher_str[i - palindromic_length[i]]) {
                palindromic_length[i]++;
            }

            if (mx < i + palindromic_length[i]) {
                mx = i + palindromic_length[i];
                center_id = i;
            }

            if (palindromic_length[i] > max_length) {
                max_length = palindromic_length[i];
                max_center = i;
            }
        }

        return s.substr((max_center - max_length + 1 >> 1), max_length - 1);
    }
};
}

#endif //LEETCODE_CPP_0005_LONGEST_PALINDROMIC_SUBSTRING_H
