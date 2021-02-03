/*
 * @Author: gary.wang
 * @Date: 2021-02-03 15:39:48
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-02-03 15:48:18
 *

    Given the root of a binary tree, the depth of each node is the shortest distance to the root.

    Return the smallest subtree such that it contains all the deepest nodes in the original tree.

    A node is called the deepest if it has the largest depth possible among any node in the entire tree.

    The subtree of a node is tree consisting of that node, plus the set of all descendants of that node.

 *
 */
#include "../ITest.h"

struct TreeNode3 {
    int val;
    TreeNode3 *left;
    TreeNode3 *right;
    TreeNode3() : val(0), left(nullptr), right(nullptr) {}
    TreeNode3(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode3(int x, TreeNode3 *left, TreeNode3 *right) : val(x), left(left), right(right) {}
};

struct Result {
    TreeNode3 *node;
    int dist;
    Result(TreeNode3 *n, int d) {
        node = n;
        dist = d;
    }
};

class SmallestSubtreewithalltheDeepestNodes : public ITest {
  public:
    TreeNode3 *subtreeWithAllDeepest(TreeNode3 *root) { return dfs(root).node; }
    Result dfs(TreeNode3 *node) {
        if (node == nullptr)
            return Result(nullptr, 0);
        Result L = dfs(node->left), R = dfs(node->right);
        if (L.dist > R.dist)
            return Result(L.node, L.dist + 1);
        if (L.dist < R.dist)
            return Result(R.node, R.dist + 1);
        return Result(node, L.dist + 1);
    }
    void test() {}
};