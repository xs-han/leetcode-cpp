//
// Created by xushen on 1/27/20.
//

#ifndef LEETCODE_CPP_STRING_TO_INTEGER_ATOI_H
#define LEETCODE_CPP_STRING_TO_INTEGER_ATOI_H

#include <string>

namespace Q_0008 {
class Solution {
 public:
    int myAtoi(const std::string& str) {
        int id = 0;
        while (str[id] == ' ') {
            id++;
        }
        bool positive_flag = true;

        if (str[id] == '-') {
            positive_flag = false;
            id++;
        } else if (str[id] == '+') {
            id++;
        } else if (str[id] < '0' || str[id] > '9'){
            return 0;
        }

        int32_t result = 0;
        int8_t digit = 0;
        for (;id < str.length(); id++) {
            if (str[id] > '9' || str[id] < '0') {
                break;
            }
            digit = str[id] - '0';
            if(!positive_flag && (result < (INT32_MIN + digit) / 10)) {
                return INT32_MIN;
            } else if(positive_flag && (result > (INT32_MAX - digit)/10)) {
                return INT32_MAX;
            }
            result = 10 * result + (positive_flag ? digit : -digit);
        }
        return result;
    }
};
}

#endif //LEETCODE_CPP_STRING_TO_INTEGER_ATOI_H
