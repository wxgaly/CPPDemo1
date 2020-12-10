/*
 * @Author: gary.wang
 * @Date: 2020-12-10 15:02:07
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-10 15:13:02
 *

    At a lemonade stand, each lemonade costs $5. 

    Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).

    Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
    You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.

    Note that you don't have any change in hand at first.

    Return true if and only if you can provide every customer with correct change.

 *
 */
#include "../ITest.h"

class LemonadeChange : public ITest {
  public:
    bool lemonadeChange1(vector<int> &bills) {
        if (bills.empty()) {
            return false;
        }
        if (bills[0] != 5 || bills[1] == 20) {
            return false;
        }
        int start = 2;
        int len = bills.size();
        vector<int> temp;
        temp.push_back(bills[0]);
        for (size_t i = 1; i < len; i++) {
            if (bills[i] != 5) {

            } else {
                temp.push_back(bills[i]);
            }
        }
        return true;
    }
    /**
     * 2年前就做过，还是没记住。。。
     * https://leetcode-cn.com/problems/lemonade-change/solution/ning-meng-shui-zhao-ling-by-leetcode-sol-nvp7/
     */
    bool lemonadeChange(vector<int> &bills) {
        int five = 0, ten = 0;
        for (auto &bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    void test() {}
};