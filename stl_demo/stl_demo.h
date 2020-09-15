/*
 * @Author: wangxuguang 
 * @Date: 2020-09-10 11:32:11 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-11 11:49:29
 */
#include <iostream>
#include <vector>

using namespace std;

class ISTLTest
{
public:
    virtual void test() = 0;
    virtual ~ISTLTest() {}
};

class MapDemo : public ISTLTest
{
public:
    void test();
    MapDemo() {}
};

class SetDemo : public ISTLTest
{
public:
    void test();
    SetDemo() {}
};

class ListDemo : public ISTLTest
{
public:
    void test();
    ListDemo() {}
};

class DequeDemo : public ISTLTest
{
public:
    void test();
    DequeDemo() {}
};

class VectorDemo : public ISTLTest
{
public:
    void test();
    VectorDemo() {}
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
        vector<unique_ptr<ISTLTest>> list;
        list.push_back(make_unique<VectorDemo>());
        list.push_back(make_unique<DequeDemo>());
        list.push_back(make_unique<ListDemo>());
        list.push_back(make_unique<SetDemo>());
        list.push_back(make_unique<MapDemo>());
        for (auto &e : list)
        {
            e->test();
        }
    }
};

//打印vector
void printVector(const string &name, vector<int> &v);

//通过输入迭代器，完成集合类通用的打印函数
template <class InputIterator>
void printIterator(const string &name, InputIterator first, InputIterator last)
{
    cout << name << ":";
    for (; first != last; first++)
    {
        /* code */
        cout << " " << *first;
    }
    cout << endl;
}
