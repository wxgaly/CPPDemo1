/*
 * @Author: gary.wang
 * @Date: 2020-12-14 14:07:30
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-14 14:15:17
 *
   A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. 
   For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

   Given a string n that represents a positive decimal integer, 
   return the minimum number of positive deci-binary numbers needed so that they sum up to n.

 * 
 */
#include "../ITest.h"

class PartitioningIntoMinimumNumberOfDeciBinaryNumbers : public ITest {
  public:
    int minPartitions(string n) {
        char ret = 0;
        for (char c : n)
            if (c == '9')
                return 9;
            else if (c > ret)
                ret = c;
        return ret - '0';
    }
    void test() {
        cout << minPartitions("32") << endl;
        cout << minPartitions("82734") << endl;
        cout << minPartitions("27346209830709182346") << endl;
    }
};