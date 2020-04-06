//
// Created by xushen on 2/16/20.
//

#include <gtest/gtest.h>

#include "0037_sudoku-solver.h"

TEST(T_0037, SOLUTION) {
    std::vector<std::vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };

    Q_0037::Solution s;
    s.solveSudoku(board);
    for (const std::vector<char>& row : board) {
        for (const char e : row) {
            std::cout << e << ", ";
        }
        std::cout << std::endl;
    }
}