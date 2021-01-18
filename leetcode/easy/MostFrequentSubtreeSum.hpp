/*
 * @Author: gary.wang
 * @Date: 2021-01-18 16:39:07
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-18 16:41:08
 *

  Given the root of a tree, you are asked to find the most frequent subtree sum.
  The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
  So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

 *
 */
#include "../ITest.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class MostFrequentSubtreeSum : public ITest {
  public:
    // 都没看懂题是什么意思
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> sumFreq;
        int maxFreq = 0;
        dfs(root, sumFreq, maxFreq);
        vector<int> res;
        for (const auto &m : sumFreq) {
            if (m.second == maxFreq) {
                res.push_back(m.first);
            }
        }

        return res;
    }

    int dfs(TreeNode *root, unordered_map<int, int> &sumFreq, int &maxFreq) {
        if (!root) {
            return 0;
        }

        int sumLeft = dfs(root->left, sumFreq, maxFreq);
        int sumRight = dfs(root->right, sumFreq, maxFreq);
        auto sum = sumLeft + sumRight + root->val;
        sumFreq[sum]++;
        maxFreq = max(maxFreq, sumFreq[sum]);

        return sum;
    }
    void test() {}
};