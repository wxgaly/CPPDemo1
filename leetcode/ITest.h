/*
 * @Author: gary.wang 
 * @Date: 2020-11-04 14:48:01 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-05 17:05:47
 */

#ifndef _ITEST_H_
#define _ITEST_H_

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class ITest
{
public:
    virtual void test() = 0;
    virtual ~ITest() {}
};

#endif
