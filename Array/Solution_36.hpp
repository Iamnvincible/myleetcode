#ifndef SOLUTION_36
#define SOLUTION_36
/*
Determine if a 9x9 Sudoku board is valid.
Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

The Sudoku board could be partially filled,
where empty cells are filled with the character '.'.

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
判断给出的数独题是否符合行、列、9x9方格中都不存在重复元素
但不判定是否可解
对给出的二维向量按行、列先判断
找出每个9*9方格元素下标规律再判断

可以先把每种9个数字保存起来再交给判断
或者每次遍历的时候就判断
用数组就能拿来做判断，不必用特别的数据结构
算法库里有很多实用的函数，减少代码量
fill(start,end,value)
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
class Solution_36
{
  public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        bool res = true;
        for (size_t i = 0; i < board.size(); i++)
        {
            res = isavecvalid(board[i]);
            if (!res)
            {
                return false;
            }
        }
        std::vector<std::vector<char>> col(9);
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board.size(); j++)
            {
                if (board[j][i] != '.')
                    col[i].push_back(board[j][i]);
            }
        }
        for (auto i : col)
        {
            res = isavecvalid(i);
            if (!res)
            {
                return false;
            }
        }
        std::vector<std::vector<char>> grid(9);

        for (size_t i = 0; i < board.size(); i++)
        {

            for (size_t j = 0; j < 3; j++)
            {

                for (size_t k = 0; k < 3; k++)
                {
                    grid[i].push_back(board[(i / 3) * 3 + j][k + (i % 3) * 3]);
                }
            }
        }
        for (auto item : grid)
        {
            res = isavecvalid(item);
            if (!res)
            {
                return false;
            }
        }
        return res;
    }
    void test()
    {
        char array[9][9] = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        std::vector<std::vector<char>> board(9);

        for (size_t i = 0; i < board.size(); i++)
        {

            for (size_t j = 0; j < 9; j++)
            {
                board[i].push_back(array[i][j]);
            }
        }
        bool r = isValidSudoku(board);
        std::cout << r << std::endl;
    }

    bool isavecvalid(std::vector<char> line)
    {
        std::unordered_map<char, bool> record;

        for (size_t i = 1; i <= 9; i++)
        {
            record[i + '0'] = false;
        }

        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] == '.')
            {
                continue;
            }
            else if (record[line[i]] == false)
            {
                record[line[i]] = true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
class Solution_36_bak
{
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        bool used[9];

        for (size_t i = 0; i < 9; i++)
        {
            std::fill(used, used + 9, false);
            for (size_t j = 0; j < 9; j++)
            {
                if (!check(board[i][j], used))
                {
                    return false;
                }
            }
            std::fill(used, used + 9, false);

            for (size_t j = 0; j < 9; j++)
            {
                if (!check(board[j][i], used))
                {
                    return false;
                }
            }
        }
        for (int r = 0; r < 3; ++r)
        {
            for (int c = 0; c < 3; ++c)
            {
                std::fill(used, used + 9, false);
                for (int i = r * 3; i < r * 3 + 3; ++i)
                    for (int j = c * 3; j < c * 3 + 3; ++j)
                        if (!check(board[i][j], used))
                            return false;
            }
        }
        return true;
    }
    bool check(char ch, bool used[9])
    {
        if (ch == '.')
            return true;
        if (used[ch - '1'])
            return false;
        return used[ch - '1'] = true;
    }
};
#endif