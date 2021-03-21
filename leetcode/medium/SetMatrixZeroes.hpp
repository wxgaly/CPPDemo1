/*
 * @Author: gary.wang
 * @Date: 2021-03-21 16:54:25
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-03-21 17:20:44
 *
  
    Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

    Follow up:

    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?


 *
 */
#include "../ITest.h"

class SetMatrixZeroes : public ITest {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        vector<vector<int>> flag;
        int row = matrix.size();
        int col = matrix[0].size();
        for (size_t i = 0; i < row; i++) {
            vector<int> temp;
            for (size_t j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    temp.push_back(1);
                } else {
                    temp.push_back(0);
                }
            }
            flag.push_back(temp);
        }

        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                if (matrix[i][j] == 0 && flag[i][j] == 1) {
                    // 横向全部变为0
                    for (size_t k = 0; k < col; k++) {
                        matrix[i][k] = 0;
                    }
                    // 纵向全部变为0
                    for (size_t l = 0; l < row; l++) {
                        matrix[l][j] = 0;
                    }
                }
            }
        }
    }
    // 官方题解，一个标记
    void setZeroes1(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
            if (flag_col0) {
                matrix[i][0] = 0;
            }
        }
    }
    void test() {
        vector<vector<int>> v1 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
        setZeroes(v1);
        vector<vector<int>> v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        setZeroes(v);
    }
};