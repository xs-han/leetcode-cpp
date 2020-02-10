//
// Created by xushen on 2/10/20.
//

#ifndef LEETCODE_CPP_0028_IMPLEMENT_STRSTR_H
#define LEETCODE_CPP_0028_IMPLEMENT_STRSTR_H

#include <string>

namespace Q_0028 {

class Solution {
 public:
    int strStr(const std::string& haystack, const std::string& needle) {
        if (haystack.empty() && !needle.empty()) {
            return -1;
        }
        int ln = needle.size(), lh = haystack.size();
        if (ln == 0u) {
            return 0;
        }
        for (int i = 0; i <= lh - ln; i++) {
            if (haystack.substr(i, ln) == needle) {
                return i;
            }
        }
        return -1;
    }
};

}

#endif //LEETCODE_CPP_0028_IMPLEMENT_STRSTR_H
