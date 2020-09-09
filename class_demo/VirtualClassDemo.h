/*
 * @Author: wangxuguang 
 * @Date: 2020-09-09 11:01:54 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-09 11:27:50
 */

#include <iostream>

using namespace std;

class Animal
{
public:
    virtual ~Animal()
    {
        cout << "Destructing base" << endl;
    }
    virtual void eat()
    {
        cout << "eat something" << endl;
    }
    virtual void shout() = 0;
};
class Dog : public Animal
{
public:
    Dog() {}
    ~Dog()
    {
        cout << "Destructing Dog" << endl;
    }
    virtual void eat()
    {
        cout << "吃骨头" << endl;
    }
    virtual void shout()
    {
        cout << "汪汪！" << endl;
    }
};
class Cat1 : public Animal
{
public:
    Cat1() {}
    ~Cat1()
    {
        cout << "Destructing Cat1" << endl;
    }
    virtual void eat()
    {
        cout << "吃鱼" << endl;
    }
    virtual void shout()
    {
        cout << "喵喵~" << endl;
    }
};
class Bird1 : public Animal
{
public:
    Bird1() {}
    ~Bird1()
    {
        cout << "Destructing Bird1" << endl;
    }
    virtual void eat()
    {
        cout << "吃虫子" << endl;
    }
    virtual void shout()
    {
        cout << "叽喳!" << endl;
    }
};

class VirtualClassDemo
{
public:
    void testRuntimePolymorphism()
    {
        Animal *anim1 = new Dog;
        Animal *anim2 = new Cat1;
        Animal *anim3 = new Bird1;

        //藉由指针（或引用）调用的接口，在运行期确定指针（或引用）所指对象的真正类型，调用该类型对应的接口
        anim1->shout();
        anim2->shout();
        anim3->shout();

        testEat(anim1);
        testEat(anim2);
        testEat(anim3);

        delete anim1;
        delete anim2;
        delete anim3;
    }
    //通过虚函数，实现了运行时多态
    void testEat(Animal *anim)
    {
        anim->eat();
    }
};