/*
 * @Author: gary.wang
 * @Date: 2021-03-25 15:08:23
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-03-25 17:24:09
 *
    
    Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
    leaving only distinct numbers from the original list. Return the linked list sorted as well.
    
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

class RemoveDuplicatesfromSortedListII : public ITest {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *guard = new ListNode(0, head);
        //哨兵节点是正确的思路，一次遍历
        ListNode *cur = guard;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return guard->next;
    }
    void test() {}
};