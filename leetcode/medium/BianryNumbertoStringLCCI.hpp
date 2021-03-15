/*
 * @Author: gary.wang
 * @Date: 2021-03-15 14:28:58
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-03-15 14:30:20
 * 
 
    Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, 
    print the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR".

    Example1:

    Input: 0.625
    Output: "0.101"


 * 
 */
#include "../ITest.h"

class BianryNumbertoStringLCCI : public ITest
{
public:
    string printBin(double num) {
        string ans = "0.";
        while (num != 0) {
            num *= 2;
            if (num >= 1) { //乘2后num>=1,说明此时整数部分为1，取完该整数部分1后，num接着利用的还是其小数部分，所以要减掉整数部分（即1）
                ans += "1";
                num -= 1;
            } else { //小于1说明整数部分为0，取该整数部分0
                ans += "0";
            }
            if (ans.size() > 32) return "ERROR";
        }
        return ans;
    }
    void test()
    {
    }
};