//
// Created by xushen on 2/7/20.
//

#ifndef LEETCODE_CPP_0014_LONGEST_COMMON_PREFIX_H
#define LEETCODE_CPP_0014_LONGEST_COMMON_PREFIX_H

#include <string>
#include <vector>

namespace Q_0014 {
class Solution {
 public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string result = "";
        size_t id = 0;
        if (strs.empty()) {
            return "";
        }
        while (true) {
            for (const std::string& s : strs) {
                if (id >= s.length()) {
                    return result;
                }
            }

            char ch = strs[0][id];
            for (int i = 1 ; i < strs.size(); i++) {
                if (ch != strs[i][id]) {
                    return result;
                }
            }

            result += ch;
            id++;
        }
    }
};
}

#endif //LEETCODE_CPP_0014_LONGEST_COMMON_PREFIX_H
