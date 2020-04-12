//
// Created by xushen on 4/8/20.
//

#ifndef LEETCODE_CPP_0038_COUNT_AND_SAY_H
#define LEETCODE_CPP_0038_COUNT_AND_SAY_H

#include <string>

namespace Q_0038 {
class Solution {
public:
    std::string countAndSay(int n) {
        std::string str1;
        std::string str2;
        str1.reserve(8192);
        str2.reserve(8192);
        str1 = "1";
        std::string& num = str2;
        std::string& res = str1;
        for (int i = 1; i < n; i++) {
            std::string& tmp = num;
            num = res;
            res = tmp;
            res.clear();

            char cur_c = num[0];
            int cur_n = 1;
            for (int j = 1; j < num.size(); j++) {
                char ch = num[j];
                if (ch == cur_c) {
                    cur_n++;
                } else {
                    res.push_back(cur_n + '0');
                    res.push_back(cur_c);
                    cur_c = ch;
                    cur_n = 1;
                }
            }
            res.push_back(cur_n + '0');
            res.push_back(cur_c);
        }
        return res;
    }
};
}

#endif //LEETCODE_CPP_0038_COUNT_AND_SAY_H
