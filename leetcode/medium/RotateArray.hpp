/*
 * @Author: gary.wang
 * @Date: 2021-01-08 14:27:09
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-08 14:31:21
 *
   
    Given an array, rotate the array to the right by k steps, where k is non-negative.

    Follow up:

    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
    Could you do it in-place with O(1) extra space?
     

    Example 1:

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]


 *
 */
#include "../ITest.h"

class RotateArray : public ITest {
  public:
    int gcd(int x, int y) { return y > 0 ? gcd(y, x % y) : x; }
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate1(vector<int> &nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    void test() {}
};