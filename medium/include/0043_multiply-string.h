//
// Created by xushen on 4/16/20.
//

#ifndef LEETCODE_CPP_0042_MULTIPLY_STRING_H
#define LEETCODE_CPP_0042_MULTIPLY_STRING_H

#include <iomanip>

namespace Q_0043 {
class Solution {
public:
    std::string multiply(std::string& num1, std::string& num2) {
        std::vector<int> n1, n2;
        int l1 = num1.size();
        int l2 = num2.size();
        n1.reserve(l1 / 4 + 1);
        n2.reserve(l2 / 4 + 1);
        int n1_reminder = l1 % 4;
        int n2_reminder = l2 % 4;
        if (n1_reminder != 0) {
            n1.push_back(std::atoi(num1.substr(0, n1_reminder).c_str()));
        }
        for (int i = n1_reminder; i < l1; i += 4) {
            n1.push_back(std::atoi(num1.substr(i, 4).c_str()));
        }
        if (n2_reminder != 0) {
            n2.push_back(std::atoi(num2.substr(0, n2_reminder).c_str()));
        }
        for (int i = n2_reminder; i < l2; i += 4) {
            n2.push_back(std::atoi(num2.substr(i, 4).c_str()));
        }

        std::vector<int> r_int(n1.size() + n2.size(), 0);
        for (int i = n1.size() - 1; i >= 0; i--) {
            for (int j = n2.size() - 1; j >= 0; j--) {
                int m = r_int[i + j + 1] + n1[i] * n2[j];
                r_int[i + j + 1] = m % 10000;
                r_int[i + j] += m / 10000;
            }
        }

        std::stringstream ss;
        auto p = r_int.begin();
        while (p != r_int.end() && *p == 0) {
            p++;
        }
        if (p == r_int.end()) {
            return "0";
        }
        ss << *(p++);
        for (; p != r_int.end(); p++) {
            ss << std::setw(4) << std::setfill('0') << *p;
        }
        return ss.str();
    }
};
}

#endif //LEETCODE_CPP_0042_MULTIPLY_STRING_H
