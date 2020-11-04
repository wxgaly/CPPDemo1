/*
 * @Author: gary.wang
 * @Date: 2020-11-04 14:34:50 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-04 14:56:36
 */
#include <iostream>
#include <vector>

#include "Leetcode.h"
#include "easy/KidsWiththeGreatestNumberofCandies.hpp"

using namespace std;

void Leetcode::test()
{
    vector<unique_ptr<ITest>> list;
    list.push_back(make_unique<KidsWiththeGreatestNumberofCandies>());
    for (auto &e : list)
    {
        e->test();
    }
}
