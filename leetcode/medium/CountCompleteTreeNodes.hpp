/*
 * @Author: gary.wang
 * @Date: 2020-11-24 14:59:28
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-25 15:55:06
 *

    Given a complete binary tree, count the number of nodes.

    Note:

    Definition of a complete binary tree from Wikipedia:
    In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as
 possible. It can have between 1 and 2h nodes inclusive at the last level h.

    Example:

    Input:
        1
       / \
      2   3
     / \  /
    4  5 6

    Output: 6


 *
 */
#include "../ITest.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CountCompleteTreeNodes : public ITest {
  public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        cout << root->val << endl;
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;
    }
    int countNodes1(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        TreeNode *node = root;
        while (node->left != nullptr) {
            level++;
            node = node->left;
        }
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    bool exists(TreeNode *root, int level, int k) {
        int bits = 1 << (level - 1);
        TreeNode *node = root;
        while (node != nullptr && bits > 0) {
            if (!(bits & k)) {
                node = node->left;
            } else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
    void test() {
        TreeNode root(1);
        TreeNode left1(2);
        TreeNode right1(3);
        TreeNode left2(4);
        TreeNode right2(5);
        TreeNode left3(6);
        root.left = &left1;
        root.right = &right1;
        root.left->left = &left2;
        root.left->right = &right2;
        root.right->left = &left3;
        cout << countNodes(&root) << endl;
    }
};