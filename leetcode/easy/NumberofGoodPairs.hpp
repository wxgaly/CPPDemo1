/*
 * @Author: gary.wang 
 * @Date: 2020-11-06 14:27:01 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-06 15:01:01
 * 
    Given an array of integers nums.

    A pair (i,j) is called good if nums[i] == nums[j] and i < j.

    Return the number of good pairs.

     

    Example 1:

    Input: nums = [1,2,3,1,1,3]
    Output: 4
    Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
    Example 2:

    Input: nums = [1,1,1,1]
    Output: 6
    Explanation: Each pair in the array are good.
    Example 3:

    Input: nums = [1,2,3]
    Output: 0

 * 
 */
#include "../ITest.h"

class NumberofGoodPairs : public ITest
{
private:
    /* data */
public:
    NumberofGoodPairs(/* args */);
    ~NumberofGoodPairs();
    int numIdenticalPairs(vector<int> &nums)
    {
        int size = nums.size();
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (nums[i] == nums[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
    int numIdenticalPairs1(vector<int>& nums) {
        unordered_map <int, int> m;
        for (int num: nums) {
            ++m[num];
        }

        int ans = 0;
        for (const auto &[k, v]: m) {
            ans += v * (v - 1) / 2;
        }

        return ans;
    }
    void test()
    {
        vector<int> nums = {1, 2, 3, 1, 1, 3};
        cout << numIdenticalPairs(nums) << endl;
        cout << numIdenticalPairs1(nums) << endl;
        nums = {1, 1, 1, 1};
        cout << numIdenticalPairs(nums) << endl;
        cout << numIdenticalPairs1(nums) << endl;
        nums = {1, 2, 3};
        cout << numIdenticalPairs(nums) << endl;
        cout << numIdenticalPairs1(nums) << endl;
    }
};

NumberofGoodPairs::NumberofGoodPairs(/* args */)
{
}

NumberofGoodPairs::~NumberofGoodPairs()
{
}
