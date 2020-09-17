/*
 * @Author: Gary Wang
 * @Date: 2020-09-16 15:39:19
 * @LastEditors: Gary Wang
 * @LastEditTime: 2020-09-17 15:59:59
 * @Description: file demo
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class IFileTest
{
public:
    virtual void test() = 0;
    virtual ~IFileTest() {}
};

class BinatyFileDemo : public IFileTest
{
public:
    void test();
    BinatyFileDemo() {}
};

class RWFileDemo : public IFileTest
{
public:
    void test();
    RWFileDemo() {}
};

class CraeteFileDemo : public IFileTest
{
public:
    void test();
    CraeteFileDemo() {}
};

class FileDemo
{
private:
    /* data */
public:
    FileDemo(/* args */)
    {
        cout << "create file demo" << endl;
    }
    ~FileDemo()
    {
        cout << "release file demo" << endl;
    }
    void test()
    {
        vector<unique_ptr<IFileTest>> list;
        list.push_back(make_unique<CraeteFileDemo>());
        list.push_back(make_unique<RWFileDemo>());
        list.push_back(make_unique<BinatyFileDemo>());
        for (auto &e : list)
        {
            e->test();
        }
    }
};
