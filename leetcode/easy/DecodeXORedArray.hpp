/*
 * @Author: gary.wang
 * @Date: 2021-04-08 14:29:58
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-04-08 14:33:07
 *
    
    There is a hidden integer array arr that consists of n non-negative integers.

    It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. 
    For example, if arr = [1,0,2,1], then encoded = [1,2,3].

    You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].

    Return the original array arr. It can be proved that the answer exists and is unique.
   

 *
 */
#include "../ITest.h"

class DecodeXORedArray : public ITest {
  public:
    vector<int> decode(vector<int> &encoded, int first) {
        int size = encoded.size();
        vector<int> ans(size + 1);
        ans[0] = first;
        for (size_t i = 0; i < size; i++) {
            ans[i + 1] = encoded[i] ^ ans[i];
        }
        return ans;
    }
    void test() {}
};