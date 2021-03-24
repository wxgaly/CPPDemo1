/*
 * @Author: gary.wang
 * @Date: 2021-03-24 15:10:14
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-03-24 15:15:46
 *
    Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], 
    nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

    Return true if there is a 132 pattern in nums, otherwise, return false.

    Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?

 *
 */
#include "../ITest.h"

class Pattern132 : public ITest {
  public:
    /// 能做到 nlogn都不错了，这个n是真的狠，
    bool find132pattern(vector<int> &nums) {
        stack<int> st;
        int n = nums.size(), k = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < k)
                return true;
            while (!st.empty() and st.top() < nums[i]) {
                k = max(k, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
    void test() {}
};