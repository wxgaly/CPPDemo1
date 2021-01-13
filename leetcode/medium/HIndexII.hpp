/*
 * @Author: gary.wang
 * @Date: 2021-01-13 14:45:43
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-13 14:48:28
 *
   
    Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, 
    write a function to compute the researcher's h-index.

    According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, 
    and the other N − h papers have no more than h citations each."

    Example:

    Input: citations = [0,1,3,5,6]
    Output: 3 
    Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
                received 0, 1, 3, 5, 6 citations respectively. 
                 Since the researcher has 3 papers with at least 3 citations each and the remaining 
                 two with no more than 3 citations each, her h-index is 3.


 *
 */
#include "../ITest.h"

class HIndexII : public ITest {
  public:
    int hIndex(vector<int> &citations) {
        int idx = 0, n = citations.size();
        int pivot, left = 0, right = n - 1;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            if (citations[pivot] == n - pivot)
                return n - pivot;
            else if (citations[pivot] < n - pivot)
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        return n - left;
    }
    void test() {}
};