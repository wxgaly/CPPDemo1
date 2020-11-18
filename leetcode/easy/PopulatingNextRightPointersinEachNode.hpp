/*
 * @Author: gary.wang
 * @Date: 2020-11-18 14:14:07
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-18 14:39:54
 *

    You are given a perfect binary tree where all leaves are on the same level,
    and every parent has two children. The binary tree has the following
    definition:

        struct Node {
        int val;
        Node *left;
        Node *right;
        Node *next;
        }
        Populate each next pointer to point to its next right node. If there is no
    next right node, the next pointer should be set to NULL.

    Initially, all next pointers are set to NULL.

 *
 */
#include "../ITest.h"

class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class PopulatingNextRightPointersinEachNode : public ITest {
  public:
    Node *connect(Node *root) {
        if (root == nullptr) {
            return root;
        }
        // 初始化队列同时将第一层节点加入队列中，即根节点
        queue<Node *> Q;
        Q.push(root);

        // 外层的 while 循环迭代的是层数
        while (!Q.empty()) {

            // 记录当前队列大小
            int size = Q.size();

            // 遍历这一层的所有节点
            for (int i = 0; i < size; i++) {

                // 从队首取出元素
                Node *node = Q.front();
                Q.pop();

                // 连接
                if (i < size - 1) {
                    node->next = Q.front();
                }

                // 拓展下一层节点
                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }
        }

        // 返回根节点
        return root;
    }

    Node *connect1(Node *root) {
        if (root == nullptr) {
            return root;
        }
        if (root->left != nullptr) {
            root->left->next = root->right;
            root->right->next =
                root->next != nullptr ? root->next->left : nullptr;
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
    void test() {}
};