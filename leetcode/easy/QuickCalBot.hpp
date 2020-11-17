/*
 * @Author: gary.wang
 * @Date: 2020-11-17 14:24:12
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-17 14:31:11
 */
#include "../ITest.h"

class QuickCalBot : public ITest {
  public:
    int calculate(string s) {
        int len = s.length();
        int x = 1;
        int y = 0;
        for (size_t i = 0; i < len; i++) {
            if (s[i] == 'A') {
                x = 2 * x + y;
            } else if (s[i] == 'B') {
                y = 2 * y + x;
            }
        }
        // return x + y;
        // 数学大法牛皮
        return 1 << len;
    }
    void test() { cout << calculate("AB") << endl; }
};