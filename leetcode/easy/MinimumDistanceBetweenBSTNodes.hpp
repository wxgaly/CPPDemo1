/*
 * @Author: gary.wang
 * @Date: 2021-04-13 14:54:49
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-04-13 14:59:18
 * 
  
   Given the root of a Binary Search Tree (BST), 
   return the minimum difference between the values of any two different nodes in the tree.

 * 
 */
#include "../ITest.h"

class MinimumDistanceBetweenBSTNodes : public ITest {
  public:
    int minDiffInBST(TreeNode *root) {
        int ans = INT_MAX, pre = -1;
        dfs(root, pre, ans);
        return ans;
    }
    void dfs(TreeNode* root, int& pre, int& ans) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, pre, ans);
        if (pre == -1) {
            pre = root->val;
        } else {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }
    void test() {
        TreeNode *root = new TreeNode(20);
        root->right = new TreeNode(30);
        root->left = new TreeNode(15);
        root->right->left = new TreeNode(17);
        root->right->right = new TreeNode(32);
        cout << minDiffInBST(root) << endl;
    }
};