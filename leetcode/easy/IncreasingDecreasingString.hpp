/*
 * @Author: gary.wang
 * @Date: 2020-11-25 15:44:30
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-25 16:00:00
 *
 
    Given a string s. You should re-order the string using the following algorithm:

    Pick the smallest character from s and append it to the result.
    Pick the smallest character from s which is greater than the last appended character to the result and append it.
    Repeat step 2 until you cannot pick more characters.
    Pick the largest character from s and append it to the result.
    Pick the largest character from s which is smaller than the last appended character to the result and append it.
    Repeat step 5 until you cannot pick more characters.
    Repeat the steps from 1 to 6 until you pick all characters from s.
    In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

    Return the result string after sorting s with this algorithm.


 *
 */
#include "../ITest.h"

class IncreasingDecreasingString : public ITest {
  public:
    string sortString(string s) {
        vector<int> num(26);
        for (char &ch : s) {
            num[ch - 'a']++;
        }

        string ret;
        while (ret.length() < s.length()) {
            for (int i = 0; i < 26; i++) {
                if (num[i]) {
                    ret.push_back(i + 'a');
                    num[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (num[i]) {
                    ret.push_back(i + 'a');
                    num[i]--;
                }
            }
        }
        return ret;
    }
    void test() {
        cout << sortString("aaaabbbbcccc") << endl;
        cout << sortString("rat") << endl;
        cout << sortString("leetcode") << endl;
        cout << sortString("ggggggg") << endl;
        cout << sortString("spo") << endl;
    }
};