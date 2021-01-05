/*
 * @Author: gary.wang
 * @Date: 2021-01-05 16:05:56
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-05 16:26:42
 *
 *
    
    In a string s of lowercase letters, these letters form consecutive groups of the same character.

    For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".

    A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group.
    In the above example, "xxxx" has the interval [3,6].

    A group is considered large if it has 3 or more characters.

    Return the intervals of every large group sorted in increasing order by start index.

     

    Example 1:

    Input: s = "abbxxxxzzy"
    Output: [[3,6]]
    Explanation: "xxxx" is the only large group with start index 3 and end index 6.

 *
 *
 */
#include "../ITest.h"

class PositionsofLargeGroups : public ITest {
  public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int len = s.size();
        int left = 0;
        int right = 1;
        char temp = s[left];
        while (right < len) {
            char next = s[right];
            if (next != temp) {
                if (right - left >= 3) {
                    vector<int> res = {left, right - 1};
                    result.push_back(res);
                }
                left = right;
                temp = next;
            }
            right++;
        }

        return result;
    }
    vector<vector<int>> largeGroupPositions1(string s) {
        vector<vector<int>> ret;
        int n = s.size();
        int num = 1;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] != s[i + 1]) {
                if (num >= 3) {
                    ret.push_back({i - num + 1, i});
                }
                num = 1;
            } else {
                num++;
            }
        }
        return ret;
    }
    void test() {
        vector<vector<int>> result = largeGroupPositions("abc");
        int len = result.size();
        for (size_t i = 0; i < len; i++) {
            vector<int> temp = result[i];
            cout << temp[0] << "," << temp[1] << endl;
        }
    }
};