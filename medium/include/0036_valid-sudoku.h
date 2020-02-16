//
// Created by xushen on 2/16/20.
//

#ifndef LEETCODE_CPP_0036_VALID_SUDOKU_H
#define LEETCODE_CPP_0036_VALID_SUDOKU_H

#include <vector>

namespace Q_0036 {
class Solution {
 public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            const std::vector<char>& row = board[i];
            for (int j = 0; j < 9; j++) {
                char ch = row[j];
                if (ch != '.') {
                    for (int r = 0; r < 9; r++) {
                        if (r != i && board[r][j] == ch) {
                            return false;
                        }
                    }
                    for (int c = 0; c < 9; c++) {
                        if (c != j && row[c] == ch) {
                            return false;
                        }
                    }
                    int start_r = i - i % 3, start_c = j - j % 3;
                    for (int r = start_r; r < start_r + 3 && r != i; r++) {
                        if (r != i) {
                            for (int c = start_c; c < start_c + 3; c++) {
                                if (c != j && board[r][c] == ch) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
}

#endif //LEETCODE_CPP_0036_VALID_SUDOKU_H
