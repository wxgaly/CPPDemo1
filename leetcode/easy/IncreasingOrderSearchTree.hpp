/*
 * @Author: gary.wang 
 * @Date: 2021-04-25 14:18:33 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-04-25 14:38:03
 * 
    
   Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node 
   in the tree is now the root of the tree, and every node has no left child and only one right child.

 * 
 */
#include "../ITest.h"

class IncreasingOrderSearchTree : public ITest
{
public:
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> list;
        inroder(root, list);
        int length = list.size();
        TreeNode* res = new TreeNode(-1);
        TreeNode* temp = res;
        for (int i = 0; i < length; i++)
        {
            temp->right = new TreeNode(list[i]);
            temp = temp->right;
        }
        return res->right;
    }
    void inroder(TreeNode* root, vector<int> &list) {
        if (root == nullptr) {
            return;
        }
        inroder(root->left, list);
        list.push_back(root->val);
        inroder(root->right, list);
    }
    void test()
    {
    }
};