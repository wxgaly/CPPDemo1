#include <iostream>
#include "struct_demo/StructDemo.h"
#include "enum_demo/enum_demo.h"
#include "class_demo/ClassDemo.h"
#include "class_demo/ExtendClassDemo.h"
#include "class_demo/VirtualClassDemo.h"
#include "stl_demo/stl_demo.h"

using namespace std;
const int len = 5;
// 测试typedef
typedef unsigned char Byte;

#define MUL(x, y) ((x) * (y))

struct Person
{
    int age;
    string name;
};

class A
{
public:
    unsigned char b;
};

void test1()
{
    int arr[len] = {1, 2, 3, 4, 5};
    for (int i = 0; i < len; ++i)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    std::cout << "Hello, World!" << std::endl;

    Person person;
    person.age = 10;
    person.name = "haha";

    cout << "age: " << person.age << endl;
    cout << "name: " << person.name << endl;

    struct PersonInfo
    {
        // int age;
        // string name;
        // short x;
        char str[10];
    } pInfo;

    A a;
    a.b = 3;

    cout << "b: " << a.b << endl;

    cout << sizeof(pInfo) << endl;
    cout << sizeof(person) << endl;
    cout << sizeof(a) << endl;
}

void testStruct()
{
    StructDemo structDemo;
    structDemo.test();
}

void testEnum()
{
    WeekDey day1 = (WeekDey)3;
    WeekDey day2 = Friday;

    cout << Wednesday - Friday << endl;

    bool res = day1 > day2;
    cout << "res = " << res << endl;
}

void testTypedef()
{
    Byte x = -1;
    cout << x - 1 << endl;
}

void testException()
{
    try
    {
        /// 抛出的是引用，需要使用引用捕获异常
        /// 抛出的是指针，需要捕获指针的异常
        throw invalid_argument("非法参数异常");
    }
    catch (logic_error &e)
    {
        cout << e.what() << endl;
    }
}

void testDefine()
{
    cout << MUL(2, 335) << endl;
}

void testFriendClass()
{
    CList clist;
    clist.OutputItem();
}

/// 父类引用，即便传入子类，依然调用父类实现的方法，不会调用子类实现的方法
/// 编译器对Parent成员函数进行的是静态绑定，即根据对象定义时的类型来确定调用哪个类的成员函数
void testExtendClass(extend_class::Parent &p)
{
    p.OutputSomething();
}

void testExtendClass()
{
    extend_class::Child c;
    testExtendClass(c);
}

class Cat
{
public:
    void shout() { cout << "喵喵~" << endl; }
};
class Bird
{
public:
    void shout() { cout << "叽喳!" << endl; }
};

template <typename T>
void animalShout(T &t)
{
    t.shout();
}

void testCompilePolymorphism()
{
    Cat cat;
    animalShout(cat);
    Bird bird;
    animalShout(bird);
}

void testRuntimePolymorphism()
{
    VirtualClassDemo virtualClassDemo;
    virtualClassDemo.testRuntimePolymorphism();
}

//函数模板
template <class type, int len>
type Max(type array[len])
{
    type ret = array[0];
    for (size_t i = 0; i < len; i++)
    {
        ret = (ret > array[i]) ? ret : array[i];
    }
    return ret;
}

void testFunTemplate()
{
    int array[5] = {123, 4214, 53, 224, 5};
    int ret = Max<int, 5>(array);
    float farray[3] = {1.33, 4.422, 5.321};
    float fret = Max<float, 3>(farray);
    cout << "ret = " << ret << endl;
    cout << "fret = " << fret << endl;
}

void testSTLDemo()
{
    STLDemo stlDemo;
    stlDemo.test();
}

int main()
{
    testSTLDemo();
    return 0;
}