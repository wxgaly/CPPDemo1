/*
 * @Author: gary.wang
 * @Date: 2021-04-30 14:32:19
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-04-30 14:39:43
 *

   Given an integer array nums where every element appears three times except for one,
   which appears exactly once. Find the single element and return it.

 *
 */
#include "../ITest.h"

class SingleNumberII : public ITest {
  public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int num : nums) {
            ++map[num];
        }
        int ans = 0;
        for (auto [num, occ] : map) {
            if (occ == 1) {
                ans = num;
                break;
            }
        }
        return ans;
    }
    void test() {}
};