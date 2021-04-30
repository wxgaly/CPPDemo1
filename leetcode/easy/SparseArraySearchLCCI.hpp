/*
 * @Author: gary.wang
 * @Date: 2021-04-29 21:17:48
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-04-30 11:08:11
 *

   Given a sorted array of strings that is interspersed with empty strings, write a method to find the location of a given string.

 *
 */
#include "../ITest.h"

class SparseArraySearchLCCI : public ITest {
  public:
    int findString(vector<string> &words, string s) {
        if (words.empty())
            return -1;
        int n = words.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int m = (left + right) / 2;
            // 用来保存m值，用来恢复
            int temp = m;
            // cout << words[m] << endl;
            // 如果m位置的值为空，则向后移动，如果大于right，则停止移动
            while (words[m] == "" && m <= right) {
                m++;
            }
            if (m > right) {
                right = temp - 1;
                continue;
            }
            // 当排除非空字符后，就开始正常判断
            if (words[m] == s)
                return m;
            else if (words[m] < s)
                left = m + 1;
            else if (words[m] > s)
                right = m - 1;
        }
        // 当退出循环后，表示left>=right，此时对left位置进行判断
        if (left < n && words[left] == s)
            return left;
        else
            return -1;
    }
    void test() {}
};