/*
 * @Author: gary.wang 
 * @Date: 2020-11-10 15:07:49 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-10 15:09:37
 * 
 
    Given an integer n and an integer start.

    Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.

    Return the bitwise XOR of all elements of nums.

     

    Example 1:

    Input: n = 5, start = 0
    Output: 8
    Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
    Where "^" corresponds to bitwise XOR operator.
    Example 2:

    Input: n = 4, start = 3
    Output: 8

 * 
 */
#include "../ITest.h"

class XOROperationinanArray : public ITest
{
private:
    /* data */
public:
    XOROperationinanArray(/* args */);
    ~XOROperationinanArray();
    int xorOperation(int n, int start)
    {
        int ret = start;
        for (int i = 1; i < n; i++)
        {
            ret ^= (start + 2 * i);

        }
        return ret;
    }
    void test()
    {
        cout << xorOperation(5, 0) << endl;
        cout << xorOperation(4, 3) << endl;
        cout << xorOperation(1, 7) << endl;
        cout << xorOperation(10, 5) << endl;
    }
};

XOROperationinanArray::XOROperationinanArray(/* args */)
{
}

XOROperationinanArray::~XOROperationinanArray()
{
}
