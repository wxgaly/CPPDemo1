/*
 * @Author: gary.wang
 * @Date: 2020-12-15 14:49:23
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-15 15:10:51
 *

    Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

    (Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

    Example 1:
    Input: N = 10
    Output: 9
    Example 2:
    Input: N = 1234
    Output: 1234
    Example 3:
    Input: N = 332
    Output: 299


 *
 */
#include "../ITest.h"

class MonotoneIncreasingDigits : public ITest {
  public:
    // 题解：https://leetcode-cn.com/problems/monotone-increasing-digits/solution/dan-diao-di-zeng-de-shu-zi-by-leetcode-s-5908/
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        int i = 1;
        while (i < strN.length() && strN[i - 1] <= strN[i]) {
            i += 1;
        }
        if (i < strN.length()) {
            while (i > 0 && strN[i - 1] > strN[i]) {
                strN[i - 1] -= 1;
                i -= 1;
            }
            for (i += 1; i < strN.length(); ++i) {
                strN[i] = '9';
            }
        }
        return stoi(strN);
    }
    void test() {
        cout << monotoneIncreasingDigits(1234) << endl;
        cout << monotoneIncreasingDigits(332) << endl;
        cout << monotoneIncreasingDigits(333) << endl;
    }
};