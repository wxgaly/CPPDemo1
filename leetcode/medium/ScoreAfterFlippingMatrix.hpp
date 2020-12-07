/*
 * @Author: gary.wang
 * @Date: 2020-12-07 14:10:51
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-07 14:18:41
 *
   
    We have a two dimensional matrix A where each value is 0 or 1.

    A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

    After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

    Return the highest possible score.

     

    Example 1:

    Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
    Output: 39
    Explanation:
    Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
    0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39


 *
 */
#include "../ITest.h"

class ScoreAfterFlippingMatrix : public ITest {
  public:
    //标准答案。。。
    int matrixScore(vector<vector<int>> &A) {
        int R = A.size();
        int C = A[0].size();
        int ans = 0;
        for (size_t c = 0; c < C; c++) {
            int col = 0;
            for (size_t r = 0; r < R; r++) {
                col += A[r][c] ^ A[r][0];
            }
            ans += max(col, R - col) * (1 << (C - c - 1));
        }
        return ans;
    }
    void test() {
        vector<vector<int>> A = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
        cout << matrixScore(A) << endl;
    }
};