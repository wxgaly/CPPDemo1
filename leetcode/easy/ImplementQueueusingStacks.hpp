/*
 * @Author: gary.wang
 * @Date: 2021-03-05 14:48:19
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-03-05 14:59:58
 *

    Implement a first in first out (FIFO) queue using only two stacks.
    The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

    Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.
    Notes:

    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively.
    You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
    Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? 
    In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

 *
 */
#include "../ITest.h"

class MyQueue1 {
  private:
    stack<int> inStack, outStack;

    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

  public:
    /** Initialize your data structure here. */
    MyQueue1() {}

    /** Push element x to the back of queue. */
    void push(int x) { inStack.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (outStack.empty()) {
            in2out();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (outStack.empty()) {
            in2out();
        }
        return outStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return inStack.empty() && outStack.empty(); }
};

class ImplementQueueusingStacks : public ITest {
  public:
    void test() {
        MyQueue1 myQueue = MyQueue1();
        myQueue.push(1);                // queue is: [1]
        myQueue.push(2);                // queue is: [1, 2] (leftmost is front of the queue)
        cout << myQueue.peek() << endl; // return 1
        cout << myQueue.pop() << endl;  // return 1, queue is [2]
    }
};