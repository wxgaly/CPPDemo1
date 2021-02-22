/*
 * @Author: gary.wang
 * @Date: 2021-02-22 15:00:15
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-02-22 15:08:54
 * 
    
    Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

    A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

 * 
 */
#include "../ITest.h"

class ToeplitzMatrix : public ITest {
  public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
    void test() {}
};