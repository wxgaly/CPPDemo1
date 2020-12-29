/*
 * @Author: gary.wang
 * @Date: 2020-12-29 20:35:14
 * @Last Modified by:   gary.wang
 * @Last Modified time: 2020-12-29 20:35:14
 * 
    
    Given a sorted positive integer array nums and an integer n, 
    add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. 
    Return the minimum number of patches required.

    Example 1:

    Input: nums = [1,3], n = 6
    Output: 1 
    Explanation:
    Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
    Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
    Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
    So we only need 1 patch.

 * 
 */
#include "../ITest.h"

class PatchingArray : public ITest {
  public:
    //想到一个思路，不停的从数组第一个元素减，直到为负值，添加元素
    //继续下一个数字遍历，到n结束
    int minPatches(vector<int> &nums, int n) {
        vector<int> result;
        for (size_t i = 1; i <= n; i++)
        {
            result.push_back(i);
        }
        int res = 0;
        while(!result.empty()) {
            int len = nums.size();
            int sum = 0;
            for (size_t i = 0; i < len; i++)
            {
                sum += nums[i];
                int temp = result[0] - sum;
                if (temp == 0) {
                    result.erase(result.begin());
                    break;
                } else if (temp < 0) {
                    nums.push_back(nums[i]);
                    nums[i] = -temp;
                    res++;
                    result.erase(result.begin());
                    break;
                }
            }
        }
        return res;
    }
    //得承认自己数学太差。。。
    int minPatches1(vector<int>& nums, int n) {
        int patches = 0;
        long long x = 1;
        int length = nums.size(), index = 0;
        while (x <= n) {
            if (index < length && nums[index] <= x) {
                x += nums[index];
                index++;
            } else {
                x <<= 1;
                patches++;
            }
        }
        return patches;
    }
    void test() {
        vector<int> nums = {1,3};
        int n = 6;
        cout << minPatches(nums, n) << endl;
    }
};