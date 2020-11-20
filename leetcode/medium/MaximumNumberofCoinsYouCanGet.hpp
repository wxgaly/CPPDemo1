/*
 * @Author: gary.wang
 * @Date: 2020-11-20 14:27:33
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-20 14:47:23
 
    There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:

    In each step, you will choose any 3 piles of coins (not necessarily consecutive).
    Of your choice, Alice will pick the pile with the maximum number of coins.
    You will pick the next pile with maximum number of coins.
    Your friend Bob will pick the last pile.
    Repeat until there are no more piles of coins.
    Given an array of integers piles where piles[i] is the number of coins in the ith pile.

    Return the maximum number of coins which you can have.

     

    Example 1:

    Input: piles = [2,4,1,2,7,8]
    Output: 9
    Explanation: Choose the triplet (2, 7, 8), Alice Pick the pile with 8 coins, you the pile with 7 coins and Bob the last one.
    Choose the triplet (1, 2, 4), Alice Pick the pile with 4 coins, you the pile with 2 coins and Bob the last one.
    The maximum number of coins which you can have are: 7 + 2 = 9.
    On the other hand if we choose this arrangement (1, 2, 8), (2, 4, 7) you only get 2 + 4 = 6 coins which is not optimal.


 *
 */
#include "../ITest.h"

class MaximumNumberofCoinsYouCanGet : public ITest {
  public:
    //贪心，每次选择尽量大的结果即可
    int maxCoins(vector<int> &piles) {
        sort(piles.begin(), piles.end());
        int size = piles.size();
        int left = 0;
        int right = size - 2;
        int result = 0;
        while (left < right) {
            result += piles[right];
            left++;
            right -= 2;
        }
        return result;
    }
    int maxCoins1(vector<int> &piles) {
        sort(piles.begin(), piles.end());
        int length = piles.size();
        int rounds = length / 3;
        int coins = 0;
        int index = length - 2;
        for (int i = 0; i < rounds; i++) {
            coins += piles[index];
            index -= 2;
        }
        return coins;
    }

    void test() {
        vector<int> piles = {2, 4, 1, 2, 7, 8};
        cout << maxCoins(piles) << endl;
        piles = {2, 4, 5};
        cout << maxCoins(piles) << endl;
        piles = {9, 8, 7, 6, 5, 1, 2, 3, 4};
        cout << maxCoins(piles) << endl;
    }
};