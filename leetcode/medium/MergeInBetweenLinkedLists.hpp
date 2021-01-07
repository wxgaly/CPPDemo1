/*
 * @Author: gary.wang
 * @Date: 2021-01-07 14:22:08
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-07 15:02:37
 *
   
    You are given two linked lists: list1 and list2 of sizes n and m respectively.

    Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

    The blue edges and nodes in the following figure incidate the result:
    Build the result list and return its head.

    Example 1:
    Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
    Output: [0,1,2,1000000,1000001,1000002,5]
    Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.

 *
 */
#include "../ITest.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeInBetweenLinkedLists : public ITest {
  public:
    // 一开始理解错了题意，还得优化代码
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *head = list1;
        //找到node a的前一个节点，node b的后一个节点
        ListNode *preNodeA = nullptr;
        ListNode *nextNodeB = nullptr;
        int index = 0;
        while (list1 != nullptr) {
            if (list1->next != nullptr && index + 1 == a) {
                preNodeA = list1;
            }
            if (index == b) {
                nextNodeB = list1->next;
            }
            list1 = list1->next;
            index++;
        }

        //找到list2的头和尾
        ListNode *head2 = list2;
        preNodeA->next = head2;
        ListNode *tail2 = nullptr;
        while (list2->next != nullptr) {
            list2 = list2->next;
            tail2 = list2;
        }
        tail2->next = nextNodeB;

        return head;
    }
    void printList(ListNode *list) {
        while (list != nullptr) {
            cout << list->val << ", ";
            list = list->next;
        }
        cout << endl;
    }
    void test() {
        ListNode *list1 = new ListNode(0);
        list1->next = new ListNode(1);
        list1->next->next = new ListNode(2);
        list1->next->next->next = new ListNode(3);
        list1->next->next->next->next = new ListNode(4);
        list1->next->next->next->next->next = new ListNode(5);

        ListNode *list2 = new ListNode(1000000);
        list2->next = new ListNode(1000001);
        list2->next->next = new ListNode(1000002);

        printList(mergeInBetween(list1, 3, 4, list2));

        list1 = new ListNode(0);
        list1->next = new ListNode(1);
        list1->next->next = new ListNode(2);
        list1->next->next->next = new ListNode(3);
        list1->next->next->next->next = new ListNode(4);
        list1->next->next->next->next->next = new ListNode(5);
        list1->next->next->next->next->next->next = new ListNode(6);

        list2 = new ListNode(1000000);
        list2->next = new ListNode(1000001);
        list2->next->next = new ListNode(1000002);
        list2->next->next->next = new ListNode(1000003);
        list2->next->next->next->next = new ListNode(1000004);

        printList(mergeInBetween(list1, 2, 5, list2));
    }
};