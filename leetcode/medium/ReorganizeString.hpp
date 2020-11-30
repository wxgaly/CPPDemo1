/*
 * @Author: gary.wang
 * @Date: 2020-11-30 14:18:32
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-30 14:31:31
 *

    iven a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

    If possible, output any possible result.  If not possible, return the empty string.

    Example 1:

    Input: S = "aab"
    Output: "aba"


 *
 */
#include "../ITest.h"

class ReorganizeString : public ITest {
  public:
    /*
     思路大体上没什么问题，先计数，再按照数量排序，如果最多字母的数量超过总字母数一半就无解；
     就是后续怎么再组成分叉字母的没有想出来，应该按照奇偶数的下标去排列；
     */
    string reorganizeString(string S) {
        if (S.length() < 2) {
            return S;
        }
        vector<int> counts(26, 0);
        int maxCount = 0;
        int length = S.length();
        for (int i = 0; i < length; i++) {
            char c = S[i];
            counts[c - 'a']++;
            maxCount = max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2) {
            return "";
        }
        auto cmp = [&](const char &letter1, const char &letter2) { return counts[letter1 - 'a'] < counts[letter2 - 'a']; };
        priority_queue<char, vector<char>, decltype(cmp)> queue{cmp};
        for (char c = 'a'; c <= 'z'; c++) {
            if (counts[c - 'a'] > 0) {
                queue.push(c);
            }
        }
        string sb = "";
        while (queue.size() > 1) {
            char letter1 = queue.top();
            queue.pop();
            char letter2 = queue.top();
            queue.pop();
            sb += letter1;
            sb += letter2;
            int index1 = letter1 - 'a', index2 = letter2 - 'a';
            counts[index1]--;
            counts[index2]--;
            if (counts[index1] > 0) {
                queue.push(letter1);
            }
            if (counts[index2] > 0) {
                queue.push(letter2);
            }
        }
        if (queue.size() > 0) {
            sb += queue.top();
        }
        return sb;
    }
    void test() {}
};