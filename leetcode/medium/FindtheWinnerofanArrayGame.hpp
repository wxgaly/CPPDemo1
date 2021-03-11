/*
 * @Author: gary.wang
 * @Date: 2021-03-11 19:36:58
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-03-11 20:01:13
 *

    Given an integer array arr of distinct integers and an integer k.

    A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]).
    In each round of the game, we compare arr[0] with arr[1],
    the larger integer wins and remains at position 0 and the smaller integer moves to the end of the array.
    The game ends when an integer wins k consecutive rounds.

    Return the integer which will win the game.

    It is guaranteed that there will be a winner of the game.

 *
 *
 */
#include "../ITest.h"

class FindtheWinnerofanArrayGame : public ITest {
  public:
    int getWinner(vector<int> &arr, int k) {
        int len = arr.size();
        int result = arr[0];
        if (k >= len) {
            for (size_t i = 1; i < len; i++) {
                if (arr[i] > result) {
                    result = arr[i];
                }
            }
        } else {
            int count = 0;
            int index = 1;
            while (1) {
                if (result > arr[index]) {
                    count++;
                } else {
                    count = 1;
                    int temp = arr[index];
                    arr[index] = result;
                    result = temp;
                }
                if (count >= k) {
                    break;
                }
                index++;
                if (index >= len) {
                    index = 1;
                }
            }
        }
        return result;
    }
    // 只需要遍历一遍数组即可
    int official(vector<int> &arr, int k) {
        int prev = max(arr[0], arr[1]);
        if (k == 1) {
            return prev;
        }
        int consecutive = 1;
        int maxNum = prev;
        int length = arr.size();
        for (int i = 2; i < length; i++) {
            int curr = arr[i];
            if (prev > curr) {
                consecutive++;
                if (consecutive == k) {
                    return prev;
                }
            } else {
                prev = curr;
                consecutive = 1;
            }
            maxNum = max(maxNum, curr);
        }
        return maxNum;
    }
    void test() {
        vector<int> arr = {3, 2, 1};
        int k = 10;
        cout << getWinner(arr, k) << endl;
        arr = {1, 9, 8, 2, 3, 7, 6, 4, 5};
        k = 7;
        cout << getWinner(arr, k) << endl;
        arr = {2, 1, 3, 5, 4, 6, 7};
        k = 2;
        cout << getWinner(arr, k) << endl;
    }
};