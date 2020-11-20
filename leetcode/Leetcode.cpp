/*
 * @Author: gary.wang
 * @Date: 2020-11-04 14:34:50
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-20 14:33:10
 */
#include <iostream>
#include <vector>

#include "Leetcode.h"
//简单
#include "easy/CheckFormationThroughConcatenation.hpp"
#include "easy/DesignParkingSystem.hpp"
#include "easy/GuessNumbers.hpp"
#include "easy/KidsWiththeGreatestNumberofCandies.hpp"
#include "easy/MaximumNestingDepthoftheParentheses.hpp"
#include "easy/NumberofGoodPairs.hpp"
#include "easy/NumberofStepstoReduceaNumbertoZero.hpp"
#include "easy/QuickCalBot.hpp"
#include "easy/ShuffletheArray.hpp"
#include "easy/SubtracttheProductandSumofDigitsofanInteger.hpp"
#include "easy/TakeCoins.hpp"
#include "easy/XOROperationinanArray.hpp"

//中等
#include "medium/ArithmeticSubarrays.hpp"
#include "medium/MaximumNumberofCoinsYouCanGet.hpp"

using namespace std;

void Leetcode::test() {
    vector<unique_ptr<ITest>> list;
    // list.push_back(make_unique<KidsWiththeGreatestNumberofCandies>());
    // list.push_back(make_unique<CheckFormationThroughConcatenation>());
    // list.push_back(make_unique<NumberofGoodPairs>());
    // list.push_back(make_unique<ShuffletheArray>());
    // list.push_back(make_unique<ParkingSystem>());
    // list.push_back(make_unique<XOROperationinanArray>());
    // list.push_back(make_unique<GuessNumbers>());
    // list.push_back(make_unique<TakeCoins>());
    // list.push_back(make_unique<SubtracttheProductandSumofDigitsofanInteger>());
    // list.push_back(make_unique<MaximumNestingDepthoftheParentheses>());
    // list.push_back(make_unique<NumberofStepstoReduceaNumbertoZero>());
    // list.push_back(make_unique<QuickCalBot>());
    // list.push_back(make_unique<ArithmeticSubarrays>());
    list.push_back(make_unique<MaximumNumberofCoinsYouCanGet>());

    for (auto &e : list) {
        e->test();
    }
}
