/*
 * @Author: wangxuguang 
 * @Date: 2020-09-10 11:32:11 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-11 10:31:34
 */
#include <iostream>

using namespace std;

class VectorDemo
{
public:
    void test();
};

class STLDemo
{
private:
    /* data */
public:
    STLDemo(/* args */) {}
    ~STLDemo()
    {
        cout << "delete" << endl;
    }
    void test()
    {
        VectorDemo v;
        v.test();
    }
};

//打印vector
void printVector(const string &name, vector<int> &v);
