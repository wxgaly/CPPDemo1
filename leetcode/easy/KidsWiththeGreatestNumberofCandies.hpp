/*
 * @Author: gary.wang 
 * @Date: 2020-11-04 14:43:00 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-04 15:45:07
 * 
 * 
 *  Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.

    For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number 
    of candies among them. Notice that multiple kids can have the greatest number of candies.

     

    Example 1:

    Input: candies = [2,3,5,1,3], extraCandies = 3
    Output: [true,true,true,false,true] 
    Explanation: 
    Kid 1 has 2 candies and if he or she receives all extra candies (3) will have 5 candies --- the greatest number of candies among the kids. 
    Kid 2 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids. 
    Kid 3 has 5 candies and this is already the greatest number of candies among the kids. 
    Kid 4 has 1 candy and even if he or she receives all extra candies will only have 4 candies. 
    Kid 5 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids. 
    Example 2:

    Input: candies = [4,2,1,1,2], extraCandies = 1
    Output: [true,false,false,false,false] 
    Explanation: There is only 1 extra candy, therefore only kid 1 will have the greatest number of candies among the kids regardless of who takes the extra candy.
    Example 3:

    Input: candies = [12,1,12], extraCandies = 10
    Output: [true,false,true]
     

    Constraints:

    2 <= candies.length <= 100
    1 <= candies[i] <= 100
    1 <= extraCandies <= 50
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include "../ITest.h"

using namespace std;

class KidsWiththeGreatestNumberofCandies : public ITest
{
private:
    /* data */
public:
    KidsWiththeGreatestNumberofCandies(/* args */);
    ~KidsWiththeGreatestNumberofCandies();
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies);
    void test();
};

KidsWiththeGreatestNumberofCandies::KidsWiththeGreatestNumberofCandies(/* args */)
{
    cout << "init" << endl;
}

KidsWiththeGreatestNumberofCandies::~KidsWiththeGreatestNumberofCandies()
{
    cout << "release" << endl;
}

vector<bool> KidsWiththeGreatestNumberofCandies::kidsWithCandies(vector<int> &candies, int extraCandies)
{
    //先找出最大值，用双指针
    vector<int>::iterator start = candies.begin();
    vector<int>::iterator end = candies.end();
    
    // int max = *max_element(candies.begin(), candies.end());
    int max = *start;
    while (start <= end)
    {
        if (*start > max)
        {
            max = *start;
        }
        if (*end > max)
        {
            max = *end;
        }
        start++;
        end--;
    }
    cout << "max is " << max << endl;

    vector<bool> res;
    int n = candies.size();
    for (size_t i = 0; i < n; i++)
    {
        res.push_back(candies[i] + extraCandies >= max);
    }

    return res;
}

void KidsWiththeGreatestNumberofCandies::test()
{
    cout << "test" << endl;
    vector<int> candies = {1,7,1,8,4,2,1,1};

    vector<bool> res = kidsWithCandies(candies, 1);
    for_each(res.begin(), res.end(), [&](bool val) { cout << val << " "; });
    cout << endl;
}
