//
// Created by xushen on 1/27/20.
//

#ifndef LEETCODE_CPP_0006_ZIGZAG_CONVERSION_H
#define LEETCODE_CPP_0006_ZIGZAG_CONVERSION_H

#include <string>

namespace Q_0006 {
class Solution {
 public:
    std::string convert(const std::string& s, int numRows) {
        std::string result;
        result.resize(s.length(), '\0');

        int id = 0;
        int period = std::max((numRows << 1) - 2, 1);
        std::pair<int, void*> step;
        std::pair<int, void*> step2;

        int result_id = 0;
        for (int r = 0; r < numRows; r++) {
            if (r == 0 || r == numRows - 1) {
                step.first = period;
                step.second = &step;
            } else {
                step.first = period - (r * 2);
                step.second = &step2;
                step2.first = period - step.first;
                step2.second = &step;
            }

            id = r;
            std::pair<int, void*>* p_step = &step;
            while (id < s.length() && result_id < s.length()) {
                result[result_id++] = s[id];
                id += p_step->first;
                p_step = reinterpret_cast<std::pair<int, void*>*>(p_step->second);
            }
        }

        return result;
    }
};
}

#endif //LEETCODE_CPP_0006_ZIGZAG_CONVERSION_H
