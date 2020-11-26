/*
 * @Author: gary.wang
 * @Date: 2020-11-26 16:48:03
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-26 16:51:18
 * 
 
    Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

    Return 0 if the array contains less than 2 elements.

    Example 1:

    Input: [3,6,9,1]
    Output: 3
    Explanation: The sorted form of the array is [1,3,6,9], either
                 (3,6) or (6,9) has the maximum difference 3.


 * 
 */
#include "../ITest.h"

class MaximumGap : public ITest {
  public:
    int maximumGap(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 1; i < n; i++) {
            ret = max(ret, nums[i] - nums[i - 1]);
        }
        return ret;
    }
    void test() {
        vector<int> nums = {3, 6, 9, 1};
        cout << maximumGap(nums) << endl;
    }
};