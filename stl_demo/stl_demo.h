/*
 * @Author: wangxuguang 
 * @Date: 2020-09-10 11:32:11 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-11 11:49:29
 */
#include <iostream>
#include <vector>
#include "typeinfo"

using namespace std;

class ISTLTest
{
public:
    virtual void test() = 0;
    virtual ~ISTLTest() {}
};

class ForEachDemo : public ISTLTest
{
public:
    void test();
    ForEachDemo() {}
};

class CountDemo : public ISTLTest
{
public:
    void test();
    CountDemo() {}
};

class AdjacentFindDemo : public ISTLTest
{
public:
    void test();
    AdjacentFindDemo() {}
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
        list.push_back(make_unique<AdjacentFindDemo>());
        list.push_back(make_unique<CountDemo>());
        list.push_back(make_unique<ForEachDemo>());
        for (auto &e : list)
        {
            e->test();
        }
        //RTTI,类型识别,向上转型
        ISTLTest *stl = new ForEachDemo();
        cout << typeid(*stl).name() << endl;
        ForEachDemo *foreachDemo = dynamic_cast<ForEachDemo *>(stl);
        foreachDemo->test();
        delete foreachDemo;

        //静态转换
        ISTLTest *stl1 = (ISTLTest *)new ForEachDemo();
        ForEachDemo *foreachDemo1 = static_cast<ForEachDemo *>(stl1);
        foreachDemo1->test();
        delete foreachDemo1;
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
