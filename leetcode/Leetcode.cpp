/*
 * @Author: gary.wang
 * @Date: 2020-11-04 14:34:50 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-06 14:48:57
 */
#include <iostream>
#include <vector>

#include "Leetcode.h"
#include "easy/KidsWiththeGreatestNumberofCandies.hpp"
#include "easy/CheckFormationThroughConcatenation.hpp"
#include "easy/NumberofGoodPairs.hpp"

using namespace std;

void Leetcode::test()
{
    vector<unique_ptr<ITest>> list;
    // list.push_back(make_unique<KidsWiththeGreatestNumberofCandies>());
    // list.push_back(make_unique<CheckFormationThroughConcatenation>());
    list.push_back(make_unique<NumberofGoodPairs>());


    for (auto &e : list)
    {
        e->test();
    }
}
