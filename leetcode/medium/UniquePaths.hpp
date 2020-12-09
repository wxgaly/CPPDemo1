/*
 * @Author: gary.wang
 * @Date: 2020-12-09 14:39:29
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-09 14:41:50
 *

    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

    The robot can only move either down or right at any point in time. The robot is trying to
    reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

    How many possible unique paths are there?

 *
 */
#include "../ITest.h"

class UniquePaths : public ITest {
  public:
    /**
     * 排列组合，
     * https://leetcode-cn.com/problems/unique-paths/solution/bu-tong-lu-jing-by-leetcode-solution-hzjf/
     */
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
    void test() {}
};