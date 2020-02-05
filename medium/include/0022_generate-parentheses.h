//
// Created by xushen on 2/5/20.
//

#ifndef LEETCODE_CPP_0022_GENERATE_PARENTHESES_H
#define LEETCODE_CPP_0022_GENERATE_PARENTHESES_H

#include <vector>
#include <string>

namespace Q_0022 {

class Solution {
 public:
    std::vector<std::string> result;
    int n = 0;

    std::vector<std::string> generateParenthesis(int n) {
        if (n == 0) {
            return result;
        }
        result.reserve(2 << (n << 1));
        this->n = n;

        Backtrack("", 0, 0);
        return result;
    }

    void Backtrack(const std::string& s, int num_left, int num_right) {
        if (num_left < num_right) {
            return;
        }

        if (num_left < n) {
            Backtrack(s + '(', num_left + 1, num_right);
        }
        if (num_right < n) {
            Backtrack(s + ')', num_left, num_right + 1);
        }
        if (num_left == n && num_right == n) {
            result.push_back(s);
        }
    }
};

}

#endif //LEETCODE_CPP_0022_GENERATE_PARENTHESES_H
