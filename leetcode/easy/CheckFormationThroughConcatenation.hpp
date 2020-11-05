/*
 * @Author: gary.wang 
 * @Date: 2020-11-05 14:40:26 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-05 17:07:47
 * 
 * 
    You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. 
    Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].

    Return true if it is possible to form the array arr from pieces. Otherwise, return false.

     
    Example 1:

    Input: arr = [85], pieces = [[85]]
    Output: true


 * 
 * 
 */
#include "../ITest.h"

class CheckFormationThroughConcatenation : public ITest
{
private:
    /* data */
public:
    CheckFormationThroughConcatenation(/* args */);
    ~CheckFormationThroughConcatenation();
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces);
    void test();
    bool canFormArray1(vector<int> &arr, vector<vector<int>> &pieces);
};

CheckFormationThroughConcatenation::CheckFormationThroughConcatenation(/* args */)
{
}

CheckFormationThroughConcatenation::~CheckFormationThroughConcatenation()
{
}

bool CheckFormationThroughConcatenation::canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
{
    //先转化为一位数组
    vector<int> temp;
    for (vector<vector<int>>::iterator it = pieces.begin(); it != pieces.end(); ++it)
    {
        for (int i = 0; i < (*it).size(); ++i)
        {
            temp.push_back((*it)[i]);
            cout << (*it)[i] << " ";
        }
    }
    bool retStart = true;
    bool retEnd = true;
    int size = arr.size();

    //正着遍历一遍
    for (int start = 0; start < size; start++)
    {
        if (temp[start] != arr[start])
        {
            retStart = false;
            break;
        }
    }

    //反着遍历一遍
    for (int end = size - 1; end >= 0; end--)
    {
        if (temp[end] != arr[end])
        {
            retStart = false;
            break;
        }
    }

    return retStart | retEnd;
}

/**
 * https://leetcode-cn.com/problems/check-array-formation-through-concatenation/solution/check-array-formation-by-ikaruga/
 * 
 */
bool CheckFormationThroughConcatenation::canFormArray1(vector<int> &arr, vector<vector<int>> &pieces)
{
    unordered_map<int, int> dic;
    for (int i = 0; i < pieces.size(); i++)
    {
        dic[pieces[i][0]] = i;
    }

    for (int i = 0; i < arr.size();)
    {
        if (dic.find(arr[i]) == dic.end())
            return false;
        auto &p = pieces[dic[arr[i]]];
        for (int j = 0; j < p.size(); j++, i++)
        {
            if (arr[i] != p[j])
                return false;
        }
    }
    return true;
}

void CheckFormationThroughConcatenation::test()
{
    vector<int> arr = {91, 4, 64, 78};
    vector<vector<int>> pieces = {{78}, {4, 64}, {91}};
    cout << "ret = " << canFormArray1(arr, pieces) << endl;
}
