//
// Created by xushen on 1/25/20.
//

#include <unordered_map>
#include <string>
#include <unordered_set>
#include <gtest/gtest.h>

namespace Q_0003 {

class Solution {
 public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> max_length_chars;
        int max_length = 0;
        int current_length = 0;
        for (int str_start = 0; str_start < s.length(); str_start++) {
            if (max_length + str_start >= s.length()) {
                return max_length;
            }
            current_length = 0;
            max_length_chars.clear();
            for (int str_end = str_start; str_end < s.length(); str_end++) {
                char& current_char = s[str_end];
                if (max_length_chars.find(current_char) ==
                    max_length_chars.end()) {
                    current_length += 1;
                    max_length_chars.insert(current_char);
                } else {
                    break;
                }
            }

            if (current_length > max_length) {
                max_length = current_length;
            }
        }
        return max_length;
    }
};

class SolutionFast {
 public:
    int lengthOfLongestSubstring(std::string s) {
        // Initialize sliding window.
        if (s.empty()) {
            return 0;
        }
        std::unordered_set<char> sliding_window;
        sliding_window.emplace(s[0]);
        auto window_start = s.begin();
        auto window_end = window_start + 1;
        for (; window_end != s.end(); window_end++) {
            auto loc = sliding_window.emplace(*window_end);
            if (!loc.second) {
                break;
            }
        }

        int max_length = sliding_window.size();
        while (window_end != s.end()) {
            for (; *window_start != *window_end; window_start++) {
                sliding_window.erase(*window_start);
            }
            window_start++;
            window_end++;

            for (; window_end != s.end(); window_end++) {
                auto loc = sliding_window.emplace(*window_end);
                if (!loc.second) {
                    break;
                }
            }
            int current_length = sliding_window.size();
            max_length =
                    max_length < current_length ? current_length : max_length;
        }
        return max_length;
    }
};

}