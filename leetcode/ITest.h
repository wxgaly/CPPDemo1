/*
 * @Author: gary.wang
 * @Date: 2020-11-04 14:48:01
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-18 14:30:06
 */

#ifndef _ITEST_H_
#define _ITEST_H_

#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class ITest {
  public:
    virtual void test() = 0;
    virtual ~ITest() {}
};

#endif
