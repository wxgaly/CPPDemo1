/*
 * @Author: gary.wang 
 * @Date: 2020-11-08 17:36:16 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-08 17:49:53
 

    Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

    Return the array in the form [x1,y1,x2,y2,...,xn,yn].

     

    Example 1:

    Input: nums = [2,5,1,3,4,7], n = 3
    Output: [2,3,5,4,1,7] 
    Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
    Example 2:

    Input: nums = [1,2,3,4,4,3,2,1], n = 4
    Output: [1,4,2,3,3,2,4,1]
    Example 3:

    Input: nums = [1,1,2,2], n = 2
    Output: [1,2,1,2]
     

    Constraints:

    1 <= n <= 500
    nums.length == 2n
    1 <= nums[i] <= 10^3


 * 
 */
#include "../ITest.h"

class ShuffletheArray : public ITest
{
private:
    /* data */
public:
    ShuffletheArray(/* args */);
    ~ShuffletheArray();
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ret;
        int p1 = 0;
        int p2 = n;
        for (; p1 < n; p1++, p2++)
        {
            ret.push_back(nums[p1]);
            ret.push_back(nums[p2]);
        }
        return ret;
    }
    // https://leetcode-cn.com/problems/shuffle-the-array/solution/kong-jian-fu-za-du-wei-o1-de-liang-chong-jie-fa-by/
    vector<int> shuffle2(vector<int> &nums, int n)
    {

        for (int i = 0; i < 2 * n; i++)
        {
            int j = i < n ? 2 * i : 2 * (i - n) + 1;
            nums[j] |= (nums[i] & 1023) << 10;
        }
        for (int &e : nums)
            e >>= 10;
        return nums;
    }
    void test()
    {
        vector<int> nums = {2, 5, 1, 3, 4, 7};
        int n = 3;
        vector<int> ret = shuffle2(nums, n);
        for (auto &i : ret)
        {
            cout << i << " ";
        }
    }
};

ShuffletheArray::ShuffletheArray(/* args */)
{
}

ShuffletheArray::~ShuffletheArray()
{
}
