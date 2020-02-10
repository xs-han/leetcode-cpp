//
// Created by xushen on 2/10/20.
//

#ifndef LEETCODE_CPP_0029_DIVIDE_TWO_INTEGERS_H
#define LEETCODE_CPP_0029_DIVIDE_TWO_INTEGERS_H

namespace Q_0029 {
class Solution {
 public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) {
            return 2147483647;
        }
        bool neg_flag = (dividend ^ divisor) < 0;
        size_t m_dividend = dividend < 0 ? (~dividend) + 1u: dividend;
        size_t m_divisor = std::labs(divisor);
        int n = 0;
        // Restoring method.
        size_t pre_dividend = m_dividend >> 1;
        while (m_divisor <= pre_dividend) {
            m_divisor <<= 1;
            n++;
        }

        size_t q = 0;
        while (n >= 0) {
            q <<= 1;
            if (m_dividend >= m_divisor) {
                q++;
                m_dividend -= m_divisor;
            }
            n--;
            m_divisor >>= 1;
        }

        return neg_flag ? (~q) + 1 : q;
    }
};
}

#endif //LEETCODE_CPP_0029_DIVIDE_TWO_INTEGERS_H
