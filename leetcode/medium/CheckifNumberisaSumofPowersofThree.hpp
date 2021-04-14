/*
 * @Author: gary.wang
 * @Date: 2021-04-14 15:06:23
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-04-14 15:12:18
 *
    
    Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

    An integer y is a power of three if there exists an integer x such that y == 3x.

 *
 */
#include "../ITest.h"

class CheckifNumberisaSumofPowersofThree : public ITest {
  public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
    void test() {}
};