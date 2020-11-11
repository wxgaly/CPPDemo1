/*
 * @Author: gary.wang 
 * @Date: 2020-11-11 14:58:48 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-11 15:11:53
 */
#include "../ITest.h"

class TakeCoins : public ITest
{
public:
    int minCount(vector<int> &coins)
    {
        int count = 0;
        for (auto &coin : coins)
        {
            count += coin % 2 == 0 ? coin / 2 : coin / 2 + 1;
        }
        return count;
    }
    void test()
    {
        vector<int> coins = {4, 2, 1};
        cout << minCount(coins) << endl;
        coins = {2, 3, 10};
        cout << minCount(coins) << endl;
    }
};