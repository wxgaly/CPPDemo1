/*
 * @Author: gary.wang
 * @Date: 2020-11-04 14:34:50
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-12-23 14:23:42
 */
#include <iostream>
#include <vector>

#include "Leetcode.h"
//简单
#include "easy/CheckFormationThroughConcatenation.hpp"
#include "easy/DesignParkingSystem.hpp"
#include "easy/GuessNumbers.hpp"
#include "easy/IncreasingDecreasingString.hpp"
#include "easy/KidsWiththeGreatestNumberofCandies.hpp"
#include "easy/MaximumNestingDepthoftheParentheses.hpp"
#include "easy/NumberofGoodPairs.hpp"
#include "easy/NumberofStepstoReduceaNumbertoZero.hpp"
#include "easy/QuickCalBot.hpp"
#include "easy/ShuffletheArray.hpp"
#include "easy/SubtracttheProductandSumofDigitsofanInteger.hpp"
#include "easy/TakeCoins.hpp"
#include "easy/XOROperationinanArray.hpp"
#include "easy/FirstUniqueCharacterinaString.hpp"

//中等
#include "medium/ArithmeticSubarrays.hpp"
#include "medium/CountCompleteTreeNodes.hpp"
#include "medium/Dota2Senate.hpp"
#include "medium/FourSumII.hpp"
#include "medium/MaximumNumberofCoinsYouCanGet.hpp"
#include "medium/MinimumNumberofArrowstoBurstBalloons.hpp"
#include "medium/MonotoneIncreasingDigits.hpp"
#include "medium/PartitioningIntoMinimumNumberOfDeciBinaryNumbers.hpp"
#include "medium/ScoreAfterFlippingMatrix.hpp"

//困难
#include "hard/CreateMaximumNumber.hpp"
#include "hard/MaximumGap.hpp"
#include "hard/PatchingArray.hpp"

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
    // list.push_back(make_unique<MaximumNumberofCoinsYouCanGet>());
    // list.push_back(make_unique<MinimumNumberofArrowstoBurstBalloons>());
    // list.push_back(make_unique<CountCompleteTreeNodes>());
    // list.push_back(make_unique<IncreasingDecreasingString>());
    // list.push_back(make_unique<MaximumGap>());
    // list.push_back(make_unique<FourSumII>());
    // list.push_back(make_unique<CreateMaximumNumber>());
    // list.push_back(make_unique<ScoreAfterFlippingMatrix>());
    // list.push_back(make_unique<Dota2Senate>());
    // list.push_back(make_unique<PartitioningIntoMinimumNumberOfDeciBinaryNumbers>());
    // list.push_back(make_unique<MonotoneIncreasingDigits>());
    // list.push_back(make_unique<FirstUniqueCharacterinaString>());
    list.push_back(make_unique<PatchingArray>());

    for (auto &e : list) {
        e->test();
    }
}
