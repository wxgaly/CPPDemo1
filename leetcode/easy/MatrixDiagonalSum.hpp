/*
 * @Author: gary.wang
 * @Date: 2021-01-21 15:20:21
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-21 15:36:29
 *

    Given a square matrix mat, return the sum of the matrix diagonals.

    Only include the sum of all the elements on the primary diagonal and
    all the elements on the secondary diagonal that are not part of the primary diagonal.


    Example 1:


    Input: mat = [[1,2,3],
                  [4,5,6],
                  [7,8,9]]
    Output: 25
    Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
    Notice that element mat[1][1] = 5 is counted only once.


 *
 */
#include "../ITest.h"

class MatrixDiagonalSum : public ITest {
  public:
    int diagonalSum(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();
        int center = 0;
        if (col % 2 == 1) {
            int index = (col - 1) / 2;
            center = mat[index][index];
        }
        int i, j;
        int i1 = 0, j1 = col - 1;
        int sum = 0;
        for (i = 0, j = 0; i < col; i++, j++, i1++, j1--) {
            sum += mat[i][j];
            sum += mat[i1][j1];
        }
        return sum - center;
    }
    void test() {
        vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        cout << diagonalSum(mat) << endl;
        mat = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
        cout << diagonalSum(mat) << endl;
        mat = {{5}};
        cout << diagonalSum(mat) << endl;
    }
};