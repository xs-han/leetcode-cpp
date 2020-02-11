//
// Created by xushen on 2/11/20.
//

#ifndef LEETCODE_CPP_0030_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H
#define LEETCODE_CPP_0030_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H

#include <vector>
#include <string>
#include <unordered_map>

namespace Q_0030 {

class Solution {
 public:
    std::vector<int> findSubstring(
            const std::string &s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) {
            return result;
        }

        std::unordered_map<std::string, size_t> word_id_map;
        std::vector<int> expected_vec;
        std::vector<int> expected_hist(26, 0);
        uint32_t expected_feature = 0u;
        for (size_t i = 0u; i < words.size(); i++) {
            const std::string& w = words[i];
            auto r = word_id_map.find(w);
            if (r == word_id_map.end()) {
                word_id_map[w] = expected_vec.size();
                expected_vec.push_back(1);
            } else {
                expected_vec[r->second]++;
            }
            for (char ch : w) {
                expected_hist[ch - 'a']++;
                expected_feature |= 1u << static_cast<uint8_t>(ch - 'a');
            }
        }

        const size_t all_word_size = words[0].size() * words.size();
        uint32_t feature = 0u;
        std::vector<int> hist(26, 0);
        for (size_t i = 0u; i < s.size(); i++) {
            feature |= 1u << (s[i] - 'a');
            hist[s[i] - 'a']++;
            int start = i - all_word_size;
            if (start >= 0) {
                int h = --hist[s[start] - 'a'];
                if (h == 0) {
                    feature &= ~(1u << (static_cast<uint8_t>(s[start] - 'a')));
                }
            }

            if (feature == expected_feature && hist == expected_hist) {
                std::vector<int> vec(expected_vec.size(), 0);
                size_t word_size = words[0].size();
                bool success = true;
                for (int j = 0; j < words.size(); j++) {
                    auto r = word_id_map.find(
                            s.substr(start + 1 + j * word_size, word_size));
                    if (r != word_id_map.end()) {
                        int v = ++vec[r->second];
                        if (v > expected_vec[r->second]) {
                            success = false;
                            break;
                        }
                    } else {
                        success = false;
                        break;
                    }
                }
                if (success && vec == expected_vec) {
                    result.push_back(start + 1);
                }
            }
        }

        return result;
    }
};


class Solution2 {
 public:
    std::vector<int> findSubstring(
            const std::string& s, const std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) {
            return result;
        }

        std::unordered_map<std::string, size_t> word_id_map;
        std::vector<int> expected_vec;
        for (size_t i = 0u; i < words.size(); i++) {
            const std::string& w = words[i];
            auto r = word_id_map.find(w);
            if (r == word_id_map.end()) {
                word_id_map[w] = expected_vec.size();
                expected_vec.push_back(1);
            } else {
                expected_vec[r->second]++;
            }
        }

        const size_t word_size = words[0].size();
        std::vector<int> ids(s.size(), -1);
        for (size_t i = 0u; i < s.size() - word_size + 1u; i++) {
            auto r = word_id_map.find(s.substr(i, word_size));
            if (r == word_id_map.end()) {
                continue;
            } else {
                ids[i] = r->second;
            }
        }

        for (size_t i = 0u; i < s.size() - word_size * words.size() + 1u; i++) {
            std::vector<int> test_vec = expected_vec;
            bool success = true;
            for (int j = 0; j < words.size(); j++) {
                int id = ids[i + word_size * j];
                if (id >= 0) {
                    int t = --test_vec[id];
                    if (t < 0) {
                        success = false;
                        break;
                    }
                } else {
                    success = false;
                    break;
                }
            }
            if (success) {
                result.push_back(i);
            }
        }

        return result;
    }
};

class Solution3 {
 public:
    std::vector<int> findSubstring(
            const std::string& s, const std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) {
            return result;
        }
        assert(words.size() <= 20);

        std::unordered_map<std::string, uint64_t> word_id_map;
        uint64_t id = 1u;
        uint64_t expected_id = 0u;
        for (size_t i = 0u; i < words.size(); i++) {
            const std::string& w = words[i];
            auto r = word_id_map.find(w);
            if (r == word_id_map.end()) {
                word_id_map[w] = id;
                expected_id += id;
                id <<= 3;
            } else {
                expected_id += r->second;
            }
        }

        const size_t word_size = words[0].size();
        std::vector<uint64_t> ids(s.size(), 0);
        for (size_t i = 0u; i < s.size() - word_size + 1u; i++) {
            auto r = word_id_map.find(s.substr(i, word_size));
            if (r == word_id_map.end()) {
                continue;
            } else {
                ids[i] = r->second;
            }
        }

        for (size_t i = 0u; i < s.size() - word_size * words.size() + 1u; i++) {
            uint64_t test_id = 0u;
            for (int j = 0; j < words.size(); j++) {
                test_id += ids[i + word_size * j];
            }
            if (test_id == expected_id) {
                result.push_back(i);
            }
        }

        return result;
    }
};
}

#endif //LEETCODE_CPP_0030_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H
