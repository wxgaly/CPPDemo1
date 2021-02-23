/*
 * @Author: gary.wang
 * @Date: 2021-02-23 14:38:41
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-02-23 14:55:12
 *
 *

    Today, the bookstore owner has a store open for customers.length minutes.  Every minute, some number of customers (customers[i]) enter the store,
    and all those customers leave after the end of that minute.

    On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0. 
    When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise they are satisfied.

    The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, but can only use it once.

    Return the maximum number of customers that can be satisfied throughout the day.

     
    Example 1:

    Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
    Output: 16
    Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes.
    The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.


 *
 */
#include "../ITest.h"

class GrumpyBookstoreOwner : public ITest {
  public:
    int maxSatisfied1(vector<int> &customers, vector<int> &grumpy, int X) {
        int max = 0;
        int result = 0;
        int start = 0;
        int size = customers.size();
        while (start <= size - X) {
            int sum = 0;
            for (size_t i = 0; i < start; i++) {
                sum += grumpy[i] ? 0 : customers[i];
            }

            for (size_t i = start; i < size - start; i++) {
                sum += customers[i];
            }

            for (size_t i = size - start; i < size; i++) {
                sum += grumpy[i] ? 0 : customers[i];
            }

            if (sum > max) {
                result = start;
            }

            start++;
        }

        return result;
    }
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
        int total = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                total += customers[i];
            }
        }
        int increase = 0;
        for (int i = 0; i < X; i++) {
            increase += customers[i] * grumpy[i];
        }
        int maxIncrease = increase;
        for (int i = X; i < n; i++) {
            increase = increase - customers[i - X] * grumpy[i - X] + customers[i] * grumpy[i];
            maxIncrease = max(maxIncrease, increase);
        }
        return total + maxIncrease;
    }
    void test() {}
};