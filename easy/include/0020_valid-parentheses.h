//
// Created by xushen on 2/5/20.
//

#ifndef LEETCODE_CPP_0020_VALID_PARENTHESES_H
#define LEETCODE_CPP_0020_VALID_PARENTHESES_H

#include <string>
#include <stack>

namespace Q_0020 {

const std::vector<char> left = {'(', '{', '['};
const std::vector<char> right = {')', '}', ']'};

class Solution {
 public:
    bool isValid(const std::string& s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::stack<char> data;
        for (const char& ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                data.push(ch);
            } else {
                if (data.empty()) {
                    return false;
                }
                char t = data.top();
                char diff = ch - t;
                if (diff != 1 && diff != 2) {
                    return false;
                }
                data.pop();
            }
        }
        return data.empty();
    }
};
}

#endif //LEETCODE_CPP_0020_VALID_PARENTHESES_H
