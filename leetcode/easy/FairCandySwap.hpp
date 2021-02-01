/*
 * @Author: gary.wang 
 * @Date: 2021-02-01 14:41:48 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-02-01 14:46:19
 * 
  
    Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, 
    and B[j] is the size of the j-th bar of candy that Bob has.

    Since they are friends, they would like to exchange one candy bar each so that after the exchange, 
    they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

    Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, 
    and ans[1] is the size of the candy bar that Bob must exchange.

    If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

 * 
 */
#include "../ITest.h"

class FairCandySwap : public ITest
{
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int delta = (sumA - sumB) / 2;
        unordered_set<int> rec(A.begin(), A.end());
        vector<int> ans;
        for (auto& y : B) {
            int x = y + delta;
            if (rec.count(x)) {
                ans = vector<int>{x, y};
                break;
            }
        }
        return ans;
    }
    void test()
    {
    }
};