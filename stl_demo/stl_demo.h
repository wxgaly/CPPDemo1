/*
 * @Author: wangxuguang 
 * @Date: 2020-09-10 11:32:11 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-10 21:59:16
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
