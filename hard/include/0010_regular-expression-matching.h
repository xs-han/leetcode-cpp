//
// Created by xushen on 1/29/20.
//

#ifndef LEETCODE_CPP_0010_REGULAR_EXPRESSION_MATCHING_H
#define LEETCODE_CPP_0010_REGULAR_EXPRESSION_MATCHING_H

#include <string>

namespace Q_0010 {

class Solution {
 public:
    const std::string* pt_s = nullptr;
    const std::string* pt_p = nullptr;
    bool isMatch(const std::string& s, const std::string& p) {
        int id_s = s.length() - 1;
        int id_p = p.length() - 1;
        pt_s = &s;
        pt_p = &p;

        return MatchSubstring(id_s, id_p);
    }

    bool MatchSubstring(int id_s, int id_p) {
        if (id_s < 0 && id_p < 0) {
            return true;
        } else if (id_p < 0) {
            return false;
        } else if (id_s < 0 && id_p == 0) {
            return false;
        }

        if (pt_p->at(id_p) == '.') {
            return id_s >=0 && MatchSubstring(id_s - 1, id_p - 1);
        } else if (pt_p->at(id_p) == '*') {
            return MatchSubstring(id_s, id_p - 2) ||
            (id_p > 0 && id_s >= 0 &&
            (pt_s->at(id_s) == pt_p->at(id_p - 1) || pt_p->at(id_p - 1) == '.') &&
            MatchSubstring(id_s - 1, id_p));
        } else {
            return id_p >= 0 && id_s >= 0 &&
            pt_p->at(id_p) == pt_s->at(id_s) &&
            MatchSubstring(id_s - 1, id_p - 1);
        }
    }
};

}

#endif //LEETCODE_CPP_0010_REGULAR_EXPRESSION_MATCHING_H
