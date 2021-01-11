/*
 * @Author: gary.wang
 * @Date: 2021-01-11 15:32:22
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-11 15:57:24
 *
 *
   
    You are given the head of a linked list, and an integer k.

    Return the head of the linked list after swapping the values of the kth node from 
    the beginning and the kth node from the end (the list is 1-indexed).

     
    Example 1:


    Input: head = [1,2,3,4,5], k = 2
    Output: [1,4,3,2,5]
    Example 2:

    Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
    Output: [7,9,6,6,8,7,3,0,9,5]


 *
 */
#include "../ITest.h"

struct ListNode1 {
    int val;
    ListNode1 *next;
    ListNode1() : val(0), next(nullptr) {}
    ListNode1(int x) : val(x), next(nullptr) {}
    ListNode1(int x, ListNode1 *next) : val(x), next(next) {}
};

class SwappingNodesinaLinkedList : public ITest {
  public:
    ListNode1 *swapNodes(ListNode1 *head, int k) {
        vector<ListNode1 *> arrayList;
        ListNode1 *temp = head;
        while (temp != nullptr) {
            arrayList.push_back(temp);
            temp = temp->next;
        }
        int size = arrayList.size();
        int tempVal = arrayList[k - 1]->val;
        arrayList[k - 1]->val = arrayList[size - k]->val;
        arrayList[size - k]->val = tempVal;
        return head;
    }
    // 快慢指针，知道这个方法，但是忘了怎么写。。。
    ListNode1 *swapNodes1(ListNode1 *head, int k) {
        ListNode1 *quickPoint = head; // 快指针，最后遍历整个链表
        ListNode1 *slowPoint = head;  // 慢指针，最后跑到倒数第k个
        ListNode1 *indexK = head;     // 正数第k个

        int n = 1;
        while (quickPoint->next != nullptr) {
            if (n < k) {
                // 在第k个停下，正好是正数第k个
                indexK = indexK->next;
            } else {
                // 拉开距离k后，慢指针开始追赶
                // 当快指针到达终点时，慢指针和快指针正好相差k个。即到达倒数第k个的位置
                slowPoint = slowPoint->next;
            }
            // 快指针，跑完全程
            quickPoint = quickPoint->next;
            n++;
        }

        // 交换值
        int temp = indexK->val;
        indexK->val = slowPoint->val;
        slowPoint->val = temp;

        return head;
    }
    void test() {
        ListNode1 *list1 = new ListNode1(0);
        list1->next = new ListNode1(1);
        list1->next->next = new ListNode1(2);
        list1->next->next->next = new ListNode1(3);
        list1->next->next->next->next = new ListNode1(4);
        // list1->next->next->next->next->next = new ListNode1(5);
        ListNode1 *listTemp = swapNodes1(list1, 3);
        while (listTemp != nullptr) {
            cout << listTemp->val << ", ";
            listTemp = listTemp->next;
        }
        cout << endl;
    }
};