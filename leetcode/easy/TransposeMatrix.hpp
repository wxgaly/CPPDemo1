/*
 * @Author: gary.wang
 * @Date: 2021-02-25 14:40:46
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-02-25 14:49:01
 *
   
    Given a 2D integer array matrix, return the transpose of matrix.

    The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

    Example 1:

    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[1,4,7],[2,5,8],[3,6,9]]
    Example 2:

    Input: matrix = [[1,2,3],[4,5,6]]
    Output: [[1,4],[2,5],[3,6]]

 *
 */
#include "../ITest.h"

class TransposeMatrix : public ITest {
  public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> transposed(n, vector<int>(m));
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }
    void test() {}
};