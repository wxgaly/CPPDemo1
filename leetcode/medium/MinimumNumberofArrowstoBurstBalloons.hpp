/*
 * @Author: gary.wang
 * @Date: 2020-11-23 14:17:31
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-23 14:32:47

    There are some spherical balloons spread in two-dimensional space. For each balloon,
    provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal,
    y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

    An arrow can be shot up exactly vertically from different points along the x-axis.
    A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend.
    There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

    Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to burst all balloons.

    Example 1:

    Input: points = [[10,16],[2,8],[1,6],[7,12]]
    Output: 2
    Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8]
    and [1,6]) and another arrow at x = 11 (bursting the other two balloons).

 *
 *
 */
#include "../ITest.h"

class MinimumNumberofArrowstoBurstBalloons : public ITest {
  public:
    //官方题解，极值问题，贪心，也想到了排序
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int> &u, const vector<int> &v) { return u[1] < v[1]; });
        int pos = points[0][1];
        int ans = 1;
        for (const vector<int> &balloon : points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
    void test() {
        vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
        cout << findMinArrowShots(points) << endl;
    }
};