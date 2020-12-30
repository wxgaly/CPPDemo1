/*
 * @Author: gary.wang
 * @Date: 2020-12-30 23:30:25
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-30 23:51:56
 *
    We have a collection of stones, each stone has a positive integer weight.

    Each turn, we choose the two heaviest stones and smash them together. 
    Suppose the stones have weights x and y with x <= y.  The result of this smash is:

    If x == y, both stones are totally destroyed;
    If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
    At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

     

    Example 1:

    Input: [2,7,4,1,8,1]
    Output: 1
    Explanation:
    We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
    we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
    we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
    we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.

 *
 */
#include "../ITest.h"

class LastStoneWeight : public ITest {
  public:
    int lastStoneWeight(vector<int> &stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int temp = stones[stones.size() - 1] - stones[stones.size() - 2];
            stones.pop_back();
            stones.pop_back();
            if (temp != 0) {
                stones.push_back(temp);
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
    int lastStoneWeight1(vector<int> &stones) {
        priority_queue<int> q;
        for (int s : stones) {
            q.push(s);
        }

        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a > b) {
                q.push(a - b);
            }
        }
        return q.empty() ? 0 : q.top();
    }

    void test() {
        vector<int> stones = {2, 7, 4, 1, 8, 1};
        cout << lastStoneWeight(stones) << endl;
    }
};