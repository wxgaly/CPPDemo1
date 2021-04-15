/*
 * @Author: gary.wang 
 * @Date: 2021-04-15 14:48:38 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-04-15 14:50:03
 * 
    
    You are a professional robber planning to rob houses along a street. 
    Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
    That means the first house is the neighbor of the last one. Meanwhile, 
    adjacent houses have a security system connected, 
    and it will automatically contact the police if two adjacent houses were broken into on the same night.

    Given an integer array nums representing the amount of money of each house, 
    return the maximum amount of money you can rob tonight without alerting the police.

 * 
 */
#include "../ITest.h"

class HouseRobberII : public ITest
{
public:
    // 动态规划需要一种思路，多理解一些简单的，然后套路就行
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
    void test()
    {
    }
};