/*
 * @Author: gary.wang
 * @Date: 2021-05-11 15:01:07
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-05-11 15:03:29
 *
    
    Given a string s, reverse only all the vowels in the string and return it.

    The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

 *
 */
#include "../ITest.h"

class ReverseVowelsofaString : public ITest {
  public:
    set<char> dict = {'a', 'o', 'e', 'i', 'u', 'A', 'O', 'E', 'I', 'U'};
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (!dict.count(s[i]) && i < j)
                i++;
            while (!dict.count(s[j]) && i < j)
                j--;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
    void test() {}
};