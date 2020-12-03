/*
 * @Author: gary.wang
 * @Date: 2020-12-03 20:38:56
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-03 20:52:22
 * 
 
    Count the number of prime numbers less than a non-negative number, n.

     

    Example 1:

    Input: n = 10
    Output: 4
    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

 * 
 */
#include "../ITest.h"

class CountPrimes : public ITest {
  public:
    /*
    * https://leetcode-cn.com/problems/count-primes/solution/ji-shu-zhi-shu-by-leetcode-solution/
    * 埃氏筛...
    */
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }

    void test() {}
};