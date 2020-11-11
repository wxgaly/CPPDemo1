/*
 * @Author: gary.wang
 * @Date: 2020-11-04 14:34:50 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-11 14:46:53
 */
#include <iostream>
#include <vector>

#include "Leetcode.h"
#include "easy/KidsWiththeGreatestNumberofCandies.hpp"
#include "easy/CheckFormationThroughConcatenation.hpp"
#include "easy/NumberofGoodPairs.hpp"
#include "easy/ShuffletheArray.hpp"
#include "easy/DesignParkingSystem.hpp"
#include "easy/XOROperationinanArray.hpp"
#include "easy/GuessNumbers.hpp"
using namespace std;

void Leetcode::test()
{
    vector<unique_ptr<ITest>> list;
    // list.push_back(make_unique<KidsWiththeGreatestNumberofCandies>());
    // list.push_back(make_unique<CheckFormationThroughConcatenation>());
    // list.push_back(make_unique<NumberofGoodPairs>());
    // list.push_back(make_unique<ShuffletheArray>());
    // list.push_back(make_unique<ParkingSystem>());
    // list.push_back(make_unique<XOROperationinanArray>());
    list.push_back(make_unique<GuessNumbers>());

    for (auto &e : list)
    {
        e->test();
    }
}
