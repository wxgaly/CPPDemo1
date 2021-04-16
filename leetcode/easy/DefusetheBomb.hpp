/*
 * @Author: gary.wang
 * @Date: 2021-04-16 16:08:14
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-04-16 16:22:06
 * 
   
    You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

    To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

    If k > 0, replace the ith number with the sum of the next k numbers.
    If k < 0, replace the ith number with the sum of the previous k numbers.
    If k == 0, replace the ith number with 0.
    As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

    Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!


 * 
 * 
 */
#include "../ITest.h"

class DefusetheBomb : public ITest {
  public:
    vector<int> decrypt(vector<int> &code, int k) {
        int count = code.size();
        if (k == 0) {
            for (size_t i = 0; i < count; i++) {
                code[i] = 0;
            }
            return code;
        } else if (k > 0) {
            vector<int> res(count);
            for (size_t i = 0; i < count; i++) {
                for (size_t j = 1; j <= k; j++) {
                    res[i] += code[(i + j) % count];
                }
            }
            return res;
        } else {
            vector<int> res(count);
            for (size_t i = 0; i < count; i++) {
                for (size_t j = 1; j <= -k; j++) {
                    res[i] += code[(count - j + i) % count];
                }
            }
            return res;
        }
    }
    void test() {
        vector<int> code = {2, 4, 9, 3};
        int k = -2;
        vector<int> res =  decrypt(code, k);
        for(auto &i : res) {
            cout << i << ", ";
        }
        cout << endl;
    }
};