/*
 * @Author: gary.wang
 * @Date: 2020-11-04 14:48:01
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-28 15:22:04
 */

#ifndef _ITEST_H_
#define _ITEST_H_

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class ITest {
  public:
    virtual void test() = 0;
    virtual ~ITest() {}
};

#endif
