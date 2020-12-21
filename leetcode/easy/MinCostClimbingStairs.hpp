/*
 * @Author: gary.wang
 * @Date: 2020-12-21 14:28:53
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-21 15:17:59
 *
 
    On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

    Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, 
    and you can either start from the step with index 0, or the step with index 1.

    Example 1:
    Input: cost = [10, 15, 20]
    Output: 15
    Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

 *
 */
#include "../ITest.h"

class MinCostClimbingStairs : public ITest {
  public:
    // 题解，自己写的有些问题，没处理好最后一个元素
    int minCostClimbingStairs(vector<int> &cost) {
        int len = cost.size();
        int prev = 0, curr = 0;
        for (int i = 2; i <= len; i++) {
            int next = min(curr + cost[i - 1], prev + cost[i - 2]);
            prev = curr;
            curr = next;
        }
        return curr;
    }
    void test() {}
};