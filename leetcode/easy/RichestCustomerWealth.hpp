/*
 * @Author: gary.wang
 * @Date: 2021-01-20 17:31:07
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-20 17:36:14
 */
#include "../ITest.h"

class RichestCustomerWealth : public ITest {
  public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int result = 0;
        for (auto &account : accounts) {
            int total = 0;
            for (auto value : account) {
                total += value;
            }
            result = max(result, total);
        }
        return result;
    }
    void test() {
        vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
        cout << maximumWealth(accounts) << endl;
        accounts = {{1, 5}, {7, 3}, {3, 5}};
        cout << maximumWealth(accounts) << endl;
        accounts = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
        cout << maximumWealth(accounts) << endl;
    }
};