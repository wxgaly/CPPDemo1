/*
 * @Author: gary.wang
 * @Date: 2021-04-19 14:54:11
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-04-19 15:00:33
 *

    Given an array nums and a value val, remove all instances of that value in-place and return the new length.

    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

    The order of elements can be changed. It doesn't matter what you leave beyond the new length.


 *
 */
#include "../ITest.h"

class RemoveElement : public ITest {
  public:
    int removeElement(vector<int> &nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return left;
    }
    void test() {}
};