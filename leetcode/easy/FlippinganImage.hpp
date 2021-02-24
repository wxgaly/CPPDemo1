/*
 * @Author: gary.wang
 * @Date: 2021-02-24 15:34:38
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-02-24 15:56:19
 *
   
    Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

    To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

    To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].


 *
 */
#include "../ITest.h"

class FlippinganImage : public ITest {
  public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left < right) {
                if (A[i][left] == A[i][right]) {
                    A[i][left] ^= 1;
                    A[i][right] ^= 1;
                }
                left++;
                right--;
            }
            if (left == right) {
                A[i][left] ^= 1;
            }
        }
        return A;
    }
    void printFlippinganImage(vector<vector<int>> &A) {
        for (size_t i = 0; i < A.size(); i++) {
            vector<int> temp = A[i];
            for (size_t j = 0; j < temp.size(); j++) {
                cout << temp[j] << ", ";
            }
            cout << endl;
        }
    }
    void test() {
        vector<vector<int>> A = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
        printFlippinganImage(A);
        A = flipAndInvertImage(A);
        printFlippinganImage(A);
    }
};