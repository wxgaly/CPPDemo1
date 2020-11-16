/*
 * @Author: gary.wang
 * @Date: 2020-11-16 14:21:47
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-16 15:08:39
 *

    Given a non-negative integer num, return the number of steps to reduce it to zero. 
    If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

     

    Example 1:

    Input: num = 14
    Output: 6
    Explanation: 
    Step 1) 14 is even; divide by 2 and obtain 7. 
    Step 2) 7 is odd; subtract 1 and obtain 6.
    Step 3) 6 is even; divide by 2 and obtain 3. 
    Step 4) 3 is odd; subtract 1 and obtain 2. 
    Step 5) 2 is even; divide by 2 and obtain 1. 
    Step 6) 1 is odd; subtract 1 and obtain 0.

 *
 */
#include "../ITest.h"

class NumberofStepstoReduceaNumbertoZero : public ITest {
  public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num != 0) {
            if (num % 2 == 0) {
                num = num / 2;
            } else {
                num = num - 1;
            }
            count++;
        }
        return count;
    }
    void test() {
        cout << numberOfSteps(14) << endl;
        cout << numberOfSteps(8) << endl;
        cout << numberOfSteps(123) << endl;
    }
};