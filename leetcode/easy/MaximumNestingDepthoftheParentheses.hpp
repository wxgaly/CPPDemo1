/*
 * @Author: gary.wang
 * @Date: 2020-11-13 14:07:09
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-13 14:35:17
 *
    
    A string is a valid parentheses string (denoted VPS) if it meets one of the following:

    It is an empty string "", or a single character not equal to "(" or ")",
    It can be written as AB (A concatenated with B), where A and B are VPS's, or
    It can be written as (A), where A is a VPS.
    We can similarly define the nesting depth depth(S) of any VPS S as follows:

    depth("") = 0
    depth(C) = 0, where C is a string with a single character not equal to "(" or ")".
    depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
    depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
    For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

    Given a VPS represented as string s, return the nesting depth of s.


 *
 */
#include "../ITest.h"

class MaximumNestingDepthoftheParentheses : public ITest {
  public:
    int maxDepth(string s) {
        int len = s.length();
        int maxDepth = 0;
        int tempDepth = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                tempDepth++;
            } else if (s[i] == ')') {
                maxDepth = max(maxDepth, tempDepth);
                tempDepth--;
            }
        }
        return maxDepth;
    }
    void test() {
        cout << maxDepth("(1+(2*3)+((8)/4))+1") << endl;
        cout << maxDepth("(1)+((2))+(((3)))") << endl;
        cout << maxDepth("1+(2*3)/(2-1)") << endl;
    }
};