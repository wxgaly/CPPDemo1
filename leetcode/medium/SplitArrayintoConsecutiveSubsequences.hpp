/*
 * @Author: gary.wang
 * @Date: 2020-12-04 16:16:03
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-04 16:25:35


    Given an array nums sorted in ascending order, return true if and only if you can split it into 1 or more subsequences
    such that each subsequence consists of consecutive integers and has length at least 3.

    Example 1:

    Input: [1,2,3,3,4,5]
    Output: True
    Explanation:
    You can split them into two consecutive subsequences :
    1, 2, 3
    3, 4, 5


 *
 */
#include "../ITest.h"

class SplitArrayintoConsecutiveSubsequences : public ITest {
  public:
    /*
    * 自己大概是个傻子吧~
    */
     bool isPossible(vector<int> &nums) {
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;
        for (auto &x : nums) {
            int count = countMap[x] + 1;
            countMap[x] = count;
        }
        for (auto &x : nums) {
            int count = countMap[x];
            if (count > 0) {
                int prevEndCount = endMap[x - 1];
                if (prevEndCount > 0) {
                    countMap[x] = count - 1;
                    endMap[x - 1] = prevEndCount - 1;
                    endMap[x] = endMap[x] + 1;
                } else {
                    int count1 = countMap[x + 1];
                    int count2 = countMap[x + 2];
                    if (count1 > 0 && count2 > 0) {
                        countMap[x] = count - 1;
                        countMap[x + 1] = count1 - 1;
                        countMap[x + 2] = count2 - 1;
                        endMap[x + 2] = endMap[x + 2] + 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void test() {}
};