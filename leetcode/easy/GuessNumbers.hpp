/*
 * @Author: gary.wang 
 * @Date: 2020-11-11 14:43:14 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2020-11-11 14:46:14
 */
#include "../ITest.h"

class GuessNumbers : public ITest
{
private:
    /* data */
public:
    GuessNumbers(/* args */);
    ~GuessNumbers();
    int game(vector<int> &guess, vector<int> &answer)
    {
        int size = guess.size();
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (guess[i] == answer[i])
            {
                count++;
            }
        }
        return count;
    }
    void test()
    {
        vector<int> guess = {1, 2, 3};
        vector<int> answer = {1, 2, 3};
        cout << game(guess, answer) << endl;
    }
};

GuessNumbers::GuessNumbers(/* args */)
{
}

GuessNumbers::~GuessNumbers()
{
}
