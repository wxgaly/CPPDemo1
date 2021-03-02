/*
 * @Author: gary.wang
 * @Date: 2021-03-02 20:47:11
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-03-02 20:54:29
 *

    Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (
        row1, col1) and lower right corner (row2, col2).


    The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

    Example:
    Given matrix = [
    [3, 0, 1, 4, 2],
    [5, 6, 3, 2, 1],
    [1, 2, 0, 1, 5],
    [4, 1, 0, 1, 7],
    [1, 0, 3, 0, 5]
    ]

    sumRegion(2, 1, 4, 3) -> 8
    sumRegion(1, 1, 2, 2) -> 11
    sumRegion(1, 2, 2, 4) -> 12
    Note:
    You may assume that the matrix does not change.
    There are many calls to sumRegion function.
    You may assume that row1 ≤ row2 and col1 ≤ col2.


 *
 *
 */
#include "../ITest.h"

class RangeSumQuery2DImmutable : public ITest {
  public:
    vector<vector<int>> sums;

    // 重复计算，且还是二维
    int sumRegion1(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (size_t i = col1; i < col2; i++) {
            for (size_t j = row1; j < row2; j++) {
                sum += sums[i][j];
            }
        }
        return sum;
    }

    vector<vector<int>> sums;

    RangeSumQuery2DImmutable(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            sums.resize(m, vector<int>(n + 1));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    sums[i][j + 1] = sums[i][j] + matrix[i][j];
                }
            }
        }
    }

    // 一维前缀和
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += sums[i][col2 + 1] - sums[i][col1];
        }
        return sum;
    }
    void test() {}
};