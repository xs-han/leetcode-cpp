//
// Created by xushen on 1/31/20.
//

#ifndef LEETCODE_CPP_0013_ROMAN_TO_INTEGER_H
#define LEETCODE_CPP_0013_ROMAN_TO_INTEGER_H

namespace Q_0013 {

const std::vector<std::string> thousands = {
        "MMM",
        "MM",
        "M"
};
const std::vector<std::string> hundreds = {
        "CM",
        "DCCC",
        "DCC",
        "DC",
        "D",
        "CD",
        "CCC",
        "CC",
        "C"
};
const std::vector<std::string> tens = {
        "XC",
        "LXXX",
        "LXX",
        "LX",
        "L",
        "XL",
        "XXX",
        "XX",
        "X"
};
const std::vector<std::string> ones = {
        "IX",
        "VIII",
        "VII",
        "VI",
        "V",
        "IV",
        "III",
        "II",
        "I"
};
class Solution {
 public:
    int romanToInt(const std::string& s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        size_t id = 0;
        int result = 0;
        if (s.empty()) {
            return 0;
        }

        for (auto p_thou = thousands.begin(); p_thou != thousands.end(); p_thou++) {
            if (s.substr(id, p_thou->length()) == *p_thou) {
                result += (thousands.end() - p_thou) * 1000;
                id += p_thou->length();
                break;
            }
        }

        for (auto p_hun = hundreds.begin(); p_hun != hundreds.end(); p_hun++) {
            if (s.substr(id, p_hun->length()) == *p_hun) {
                result += (hundreds.end() - p_hun) * 100;
                id += p_hun->length();
                break;
            }
        }

        for (auto p_ten = tens.begin(); p_ten != tens.end(); p_ten++) {
            if (s.substr(id, p_ten->length()) == *p_ten) {
                result += (tens.end() - p_ten) * 10;
                id += p_ten->length();
                break;
            }
        }

        for (auto p_one = ones.begin(); p_one != ones.end(); p_one++) {
            if (s.substr(id, p_one->length()) == *p_one) {
                result += (ones.end() - p_one);
                break;
            }
        }

        return result;
    }
};
}

#endif //LEETCODE_CPP_0013_ROMAN_TO_INTEGER_H
