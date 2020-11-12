/*
 * @Author: gary.wang 
 * @Date: 2020-11-12 14:08:33 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-12 14:26:31
 * 
 
    Given an integer number n, return the difference between the product of its digits and the sum of its digits.
     

    Example 1:

    Input: n = 234
    Output: 15 
    Explanation: 
    Product of digits = 2 * 3 * 4 = 24 
    Sum of digits = 2 + 3 + 4 = 9 
    Result = 24 - 9 = 15

 * 
 */
#include "../ITest.h"

class SubtracttheProductandSumofDigitsofanInteger : public ITest
{
public:
    int subtractProductAndSum(int n)
    {
        int sum = 0;
        int product = 1;
        while (n != 0)
        {
            int mod = n % 10;
            sum += mod;
            product *= mod;
            n = n / 10;
        }
        return product - sum;
    }
    void test()
    {
        cout << subtractProductAndSum(234) << endl;
        cout << subtractProductAndSum(4421) << endl;
    }
};