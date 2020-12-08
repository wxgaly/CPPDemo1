/*
 * @Author: gary.wang
 * @Date: 2020-12-08 14:22:55
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-08 14:27:13
 *
 *
    
    Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

    Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

    0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
    F.length >= 3;
    and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
    Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

    Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

 *
 */
#include "../ITest.h"

class SplitArrayintoFibonacciSequence : public ITest {
  public:
    //回溯法。。。
    vector<int> splitIntoFibonacci(string S) {
        vector<int> list;
        backtrack(list, S, S.length(), 0, 0, 0);
        return list;
    }
    bool backtrack(vector<int> &list, string S, int length, int index, long long sum, int prev) {
        if (index == length) {
            return list.size() >= 3;
        }
        long long curr = 0;
        for (int i = index; i < length; i++) {
            if (i > index && S[index] == '0') {
                break;
            }
            curr = curr * 10 + S[i] - '0';
            if (curr > INT_MAX) {
                break;
            }
            if (list.size() >= 2) {
                if (curr < sum) {
                    continue;
                } else if (curr > sum) {
                    break;
                }
            }
            list.push_back(curr);
            if (backtrack(list, S, length, i + 1, prev + curr, curr)) {
                return true;
            }
            list.pop_back();
        }
        return false;
    }
    void test() {}
};