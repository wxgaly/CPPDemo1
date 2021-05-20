/*
 * @Author: gary.wang
 * @Date: 2021-05-20 15:05:19
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-05-20 15:17:25
 *
    
    You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

    The population of some year x is the number of people alive during that year. 
    The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. 
    Note that the person is not counted in the year that they die.

    Return the earliest year with the maximum population.

 *
 */
#include "../ITest.h"

class MaximumPopulationYear : public ITest {
  public:
    int maximumPopulation(vector<vector<int>> &logs) {
        int offset = 1950;
        vector<int> delta(101, 0); // 变化量
        for (auto &&log : logs) {
            ++delta[log[0] - offset];
            --delta[log[1] - offset];
        }
        int mx = 0;   // 人口数量最大值
        int res = 0;  // 最大值对应的最小下标
        int curr = 0; // 每一年的人口数量
        // 前缀和
        for (int i = 0; i < 101; ++i) {
            curr += delta[i];
            if (curr > mx) {
                mx = curr;
                res = i;
            }
        }
        return res + offset; // 转回对应的年份
    }
    void test() {}
};