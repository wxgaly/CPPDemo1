/*
 * @Author: gary.wang
 * @Date: 2021-01-27 15:10:39
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-27 15:13:41
 * 
  
    Given a balanced parentheses string S, compute the score of the string based on the following rule:

    () has score 1
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.
     

    Example 1:

    Input: "()"
    Output: 1


 * 
 */
#include "../ITest.h"

class ScoreofParentheses : public ITest {
  public:
    int scoreOfParentheses(string S) {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(') {
                bal++;
            } else {
                bal--;
                if (S[i - 1] == '(')
                    ans += 1 << bal;
            }
        }
        return ans;
    }
    void test() {
        cout << scoreOfParentheses("()") << endl;
        cout << scoreOfParentheses("(())") << endl;
        cout << scoreOfParentheses("(()())") << endl;
        cout << scoreOfParentheses("(()(()))") << endl;
    }
};