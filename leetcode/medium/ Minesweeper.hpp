/*
 * @Author: gary.wang
 * @Date: 2021-01-12 16:28:07
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-12 16:29:20
 *

    Let's play the minesweeper game (Wikipedia, online game)!

    You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square,
    'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines,
    digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

    Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'),
    return the board after revealing this position according to the following rules:

    If a mine ('M') is revealed, then the game is over - change it to 'X'.
    If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares
    should be revealed recursively. If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8')
    representing the number of adjacent mines. Return the board when no more squares will be revealed.  

    Example 1:

    Input:

    [['E', 'E', 'E', 'E', 'E'],
    ['E', 'E', 'M', 'E', 'E'],
    ['E', 'E', 'E', 'E', 'E'],
    ['E', 'E', 'E', 'E', 'E']]

    Click : [3,0]

    Output:

    [['B', '1', 'E', '1', 'B'],
    ['B', '1', 'M', '1', 'B'],
    ['B', '1', '1', '1', 'B'],
    ['B', 'B', 'B', 'B', 'B']]


 *
 */
#include "../ITest.h"

class Minesweeper : public ITest {
  public:
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};
    // 好好学习一下扫雷，可以做个游戏。。。
    void dfs(vector<vector<char>> &board, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];
            if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
                continue;
            }
            // 不用判断 M，因为如果有 M 的话游戏已经结束了
            cnt += board[tx][ty] == 'M';
        }
        if (cnt > 0) {
            // 规则 3
            board[x][y] = cnt + '0';
        } else {
            // 规则 2
            board[x][y] = 'B';
            for (int i = 0; i < 8; ++i) {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                // 这里不需要在存在 B 的时候继续扩展，因为 B 之前被点击的时候已经被扩展过了
                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E') {
                    continue;
                }
                dfs(board, tx, ty);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            // 规则 1
            board[x][y] = 'X';
        } else {
            dfs(board, x, y);
        }
        return board;
    }
    void test() {}
};