/*
 * @Author: gary.wang
 * @Date: 2020-11-27 15:40:17
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-27 16:12:48
 *
 
    Given four lists A, B, C, D of integer values, 
    compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

    To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
    All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.


 *
 */
#include "../ITest.h"

class FourSumII : public ITest {
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        unordered_map<int, int> countAB;
        for (int u : A) {
            for (int v : B) {
                ++countAB[u + v];
            }
        }
        int ans = 0;
        for (int u : C) {
            for (int v : D) {
                if (countAB.count(-u - v)) {
                    ans += countAB[-u - v];
                }
            }
        }
        return ans;
    }
    void test() {
        vector<int> A = {1, 2};
        vector<int> B = {-2, -1};
        vector<int> C = {-1, 2};
        vector<int> D = {0, 2};
        cout << fourSumCount(A, B, C, D) << endl;
    }
};