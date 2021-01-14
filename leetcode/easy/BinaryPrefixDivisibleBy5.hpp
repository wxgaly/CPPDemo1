/*
 * @Author: gary.wang
 * @Date: 2021-01-14 14:47:16
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-14 14:48:42
 *
   
    Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] interpreted as 
    a binary number (from most-significant-bit to least-significant-bit.)

    Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

    Example 1:

    Input: [0,1,1]
    Output: [true,false,false]
    Explanation: 
    The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  Only the first number is divisible by 5, so answer[0] is true.


 *
 */
#include "../ITest.h"

class BinaryPrefixDivisibleBy5 : public ITest {
  public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        vector<bool> list;
        int prefix = 0;
        int length = A.size();
        for (int i = 0; i < length; i++) {
            prefix = ((prefix << 1) + A[i]) % 5;
            list.emplace_back(prefix == 0);
        }
        return list;
    }
    void test() {}
};