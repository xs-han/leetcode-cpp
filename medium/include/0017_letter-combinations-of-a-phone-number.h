//
// Created by xushen on 2/2/20.
//

#ifndef LEETCODE_CPP_0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define LEETCODE_CPP_0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H

#include <string>
#include <vector>

namespace Q_0017 {

const static std::vector<std::string> letters = {
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
};
class Solution {
 public:
    std::vector<std::string> results;

    std::vector<std::string>& letterCombinations(const std::string& digits) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        results.clear();
        if (digits.empty()) {
            return results;
        }

        size_t total_num_strs = 1u;
        for (const char& ch : digits) {
            total_num_strs *= letters[ch - '0'].size();
        }
        results.reserve(total_num_strs);
        results.resize(1, "");

        for (int i = 0; i < digits.size(); i++) {
            size_t n = digits[i] - '0';
            size_t previous_size = results.size();
            results.resize(previous_size * letters[n].size());
            for (int l = 1; l < letters[n].size(); l++) {
                std::copy(results.begin(),
                          results.begin() + previous_size,
                          results.begin() + previous_size * l);
            }
            for (int l = 0; l < letters[n].size(); l++) {
                char ch = letters[n][l];
                for (int k = 0; k < previous_size; k++) {
                    results[l * previous_size + k] += ch;
                }
            }
        }

        return results;
    }
};


class Solution2 {
 public:
    std::vector<std::string> results;
    const std::string* p_digits;
    std::vector<std::string>& letterCombinations(const std::string& digits) {
        results.clear();
        if (digits.empty()) {
            return results;
        }
        p_digits = &digits;
        AddLetter("", 0);
        return results;
    }

    void AddLetter(const std::string& str, int i) {
        if (i < p_digits->size()) {
            size_t n = p_digits->at(i) - '0';
            const std::string & letter_str = letters[n];
            for (const char ch : letter_str) {
                std::string new_str = str + ch;
                AddLetter(new_str, i + 1);
            }
        } else {
            results.push_back(str);
        }
    }
};
}

#endif //LEETCODE_CPP_0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
