/*
 * @Author: gary.wang
 * @Date: 2021-02-08 14:25:05
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-02-08 14:54:22
 *
    
    Given a binary search tree, return a balanced binary search tree with the same node values.

    A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

    If there is more than one answer, return any of them.

 *
 */
#include "../ITest.h"

struct TreeNodeB {
    int val;
    TreeNodeB *left;
    TreeNodeB *right;
    TreeNodeB(int x) : val(x), left(NULL), right(NULL) {}
};

class BalanceaBinarySearchTree : public ITest {
  public:
    vector<int> inorderSeq;

    // 思路果然就是中序遍历还原二叉搜索树
    void getInorder(TreeNodeB *o) {
        if (o->left) {
            getInorder(o->left);
        }
        inorderSeq.push_back(o->val);
        if (o->right) {
            getInorder(o->right);
        }
    }

    TreeNodeB *build(int l, int r) {
        int mid = (l + r) >> 1;
        TreeNodeB *o = new TreeNodeB(inorderSeq[mid]);
        if (l <= mid - 1) {
            o->left = build(l, mid - 1);
        }
        if (mid + 1 <= r) {
            o->right = build(mid + 1, r);
        }
        return o;
    }

    TreeNodeB *balanceBST(TreeNodeB *root) {
        getInorder(root);
        return build(0, inorderSeq.size() - 1);
    }
    void test() {}
};