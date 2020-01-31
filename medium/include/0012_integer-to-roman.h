//
// Created by xushen on 1/31/20.
//

#ifndef LEETCODE_CPP_0012_INTEGER_TO_ROMAN_H
#define LEETCODE_CPP_0012_INTEGER_TO_ROMAN_H

#include <iostream>
#include <string>
#include <vector>

namespace Q_0012 {

const std::vector<std::string> thousands = {
        "",
        "M",
        "MM",
        "MMM",
};
const std::vector<std::string> hundreds = {
        "",
        "C",
        "CC",
        "CCC",
        "CD",
        "D",
        "DC",
        "DCC",
        "DCCC",
        "CM",
};
const std::vector<std::string> tens = {
        "",
        "X",
        "XX",
        "XXX",
        "XL",
        "L",
        "LX",
        "LXX",
        "LXXX",
        "XC",
};
const std::vector<std::string> ones = {
        "",
        "I",
        "II",
        "III",
        "IV",
        "V",
        "VI",
        "VII",
        "VIII",
        "IX",
};

class Solution {
 public:
    std::string intToRoman(int num) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        const int n3 = num / 1000;
        const int n2 = (num % 1000) / 100;
        const int n1 = (num % 100) / 10;
        const int n0 = num % 10;

        return thousands[n3] + hundreds[n2] + tens[n1] + ones[n0];
    }
};

}

#endif //LEETCODE_CPP_0012_INTEGER_TO_ROMAN_H
