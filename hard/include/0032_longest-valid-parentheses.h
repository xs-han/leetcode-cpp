//
// Created by xushen on 2/14/20.
//

#ifndef LEETCODE_CPP_0032_LONGEST_VALID_PARENTHESES_H
#define LEETCODE_CPP_0032_LONGEST_VALID_PARENTHESES_H

#include <string>
#include <stack>

namespace Q_0032 {
class Solution {
 public:
    int longestValidParentheses(const std::string& s) {
        std::stack<std::string::const_iterator> data;
        data.push(s.begin() - 1);
        int max_distance = 0;
        for (auto p = s.begin(); p != s.end(); p++) {
            if (*p == '(') {
                data.push(p);
            } else {
                data.pop();
                if (data.empty()) {
                    data.push(p);
                } else {
                    int distance = p - data.top();
                    if (distance > max_distance) {
                        max_distance = distance;
                    }
                }
            }
        }
        return max_distance;
    }
};
}

#endif //LEETCODE_CPP_0032_LONGEST_VALID_PARENTHESES_H
