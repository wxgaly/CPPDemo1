/*
 * @Author: gary.wang
 * @Date: 2021-03-09 14:26:26
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-03-09 14:38:19
 *

    Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

    We repeatedly make duplicate removals on S until we no longer can.

    Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

    Example 1:

    Input: "abbaca"
    Output: "ca"
    Explanation:
    For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move. 
    The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

 *
 */
#include "../ITest.h"

class RemoveAllAdjacentDuplicatesInString : public ITest {
  public:
    // 磨蹭半天才发现是栈
    string removeDuplicates(string S) {
        string stack;
        for (char ch : S) {
            if (!stack.empty() && stack.back() == ch) {
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }
        return stack;
    }
    void test() {}
};