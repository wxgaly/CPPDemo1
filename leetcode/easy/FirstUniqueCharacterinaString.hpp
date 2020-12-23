/*
 * @Author: gary.wang
 * @Date: 2020-12-23 14:16:24
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-23 14:31:44
 
    Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

    Examples:

    s = "leetcode"
    return 0.

    s = "loveleetcode"
    return 2.

 *
 *
 */
#include "../ITest.h"

class FirstUniqueCharacterinaString : public ITest {
  public:
    int firstUniqChar(string s) {

        int index = -1;
        if (s.empty()) {
            return -1;
        }
        int map[26]{0};
        int len = s.length();
        for (size_t i = 0; i < len; i++) {
            map[s[i] - 'a'] += 1;
        }
        for (size_t i = 0; i < len; i++) {
            if (map[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return index;
    }
    void test() {
        cout << firstUniqChar("leetcode") << endl;
        cout << firstUniqChar("loveleetcode") << endl;
    }
};