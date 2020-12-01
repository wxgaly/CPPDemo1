/*
 * @Author: gary.wang
 * @Date: 2020-12-01 15:56:00
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-01 15:59:35
 *

    Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

    If target is not found in the array, return [-1, -1].

    Follow up: Could you write an algorithm with O(log n) runtime complexity?

     

    Example 1:

    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]


 *
 */
#include "../ITest.h"

class FindFirstandLastPositionofElementinSortedArray : public ITest {
  public:
    //二分查找
    int binarySearch(vector<int> &nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
    void test() {}
};