/*
 * @Author: gary.wang 
 * @Date: 2021-04-27 15:49:35 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-04-27 16:00:52
 * 
  
    Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].

 * 
 */
#include "../ITest.h"

class RangeSumofBST : public ITest
{
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
    void inOrder(TreeNode* root, int low, int high, int & res) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, low, high, res);
        if (root->val >= low && root->val <= high) {
            res += root->val;
        }
        if (root->val > high) {
            return;
        }
        inOrder(root->right, low, high, res);
    }
    void test()
    {
    }
};