/*
 * @Author: gary.wang
 * @Date: 2020-12-31 14:22:31
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-31 14:24:43
 *
    Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

    Example 1:

    Input: [[1,2],[2,3],[3,4],[1,3]]
    Output: 1
    Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

 *
 */
#include "../ITest.h"

class NonoverlappingIntervals : public ITest {
  public:
    //贪心，两年前做过的题目了，现在看到感觉还是一脸懵逼，可怕。。。
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const auto &u, const auto &v) { return u[1] < v[1]; });

        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {
                ++ans;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
    void test() {}
};