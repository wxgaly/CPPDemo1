/*
 * @Author: gary.wang
 * @Date: 2020-12-16 14:23:40
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-16 14:25:35
 *

    Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

    Example 1:

    Input: pattern = "abba", s = "dog cat cat dog"
    Output: true
    Example 2:

    Input: pattern = "abba", s = "dog cat cat fish"
    Output: false

 *
 */
#include "../ITest.h"

class WordPattern : public ITest {
  public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int m = str.length();
        int i = 0;
        for (auto ch : pattern) {
            if (i >= m) {
                return false;
            }
            int j = i;
            while (j < m && str[j] != ' ')
                j++;
            const string &tmp = str.substr(i, j - i);
            if (str2ch.count(tmp) && str2ch[tmp] != ch) {
                return false;
            }
            if (ch2str.count(ch) && ch2str[ch] != tmp) {
                return false;
            }
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;
            i = j + 1;
        }
        return i >= m;
    }
    void test() {}
};