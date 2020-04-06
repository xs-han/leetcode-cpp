//
// Created by xushen on 2/16/20.
//

#ifndef LEETCODE_CPP_0037_SUDOKU_SOLVER_H
#define LEETCODE_CPP_0037_SUDOKU_SOLVER_H

#include <vector>
#include <bitset>

namespace Q_0037 {
class Solution {
    struct Element {
        size_t i;
        size_t j;
        size_t num_choices;
    };
public:
    std::array<std::bitset<9>, 9> row_choices;
    std::array<std::bitset<9>, 9> col_choices;
    std::array<std::array<std::bitset<9>, 3>, 3> blk_choices;

    std::vector<Element> dots;

    void GetChoices(const std::vector<std::vector<char>>& board) {
        for (size_t i = 0; i < board.size(); i++) {
            const std::vector<char>& row = board[i];
            for (size_t j = 0; j < row.size(); j++) {
                const char v = row[j];
                if (v == '.') {
                    dots.push_back({i, j, 0});
                    continue;
                }
                size_t b = v - '1';
                row_choices[i].reset(b);
                col_choices[j].reset(b);
                blk_choices[i / 3][j / 3].reset(b);
            }
        }
        for (Element& e : dots) {
            std::bitset<9> v = row_choices[e.i] & col_choices[e.j] & blk_choices[e.i / 3][e.j / 3];
            e.num_choices = v.count();
        }
        std::sort(dots.begin(), dots.end(),
                [](const Element& e1, const Element& e2) {
            return e1.num_choices < e2.num_choices;
        });
    }

    bool DFSElement(
            std::vector<std::vector<char>>& board,
            const std::vector<Element>::iterator& iter) {
        if (iter == dots.end()) {
            return true;
        }
        size_t i = iter->i;
        size_t j = iter->j;
        std::bitset<9> v = row_choices[i] & col_choices[j] & blk_choices[i / 3][j / 3];
        if (!v.any()) {
            return false;
        }
        for (size_t b = 0; b < 9u; b++) {
            if (v[b]) {
                board[i][j] = '1' + b;
                row_choices[i].reset(b);
                col_choices[j].reset(b);
                blk_choices[i / 3][j / 3].reset(b);
                bool success = DFSElement(board, iter + 1);
                if (!success) {
                    board[i][j] = '.';
                    row_choices[i].set(b);
                    col_choices[j].set(b);
                    blk_choices[i / 3][j / 3].set(b);
                } else {
                    return true;
                }
            }
        }
        return false;
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        row_choices.fill(std::bitset<9>(0xfff));
        col_choices.fill(std::bitset<9>(0xfff));
        blk_choices[0].fill(std::bitset<9>(0xfff));
        blk_choices[1].fill(std::bitset<9>(0xfff));
        blk_choices[2].fill(std::bitset<9>(0xfff));
        dots.reserve(81);
        GetChoices(board);
        bool success = DFSElement(board, dots.begin());
    }
};
}

#endif //LEETCODE_CPP_0037_SUDOKU_SOLVER_H
