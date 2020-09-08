/*
 * @Author: wangxuguang 
 * @Date: 2020-09-08 18:05:01 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-08 18:22:41
 */
#include <iostream>

using namespace std;

namespace extend_class
{
    class Parent
    {
    public:
        Parent() {}
        ~Parent() {}
        void OutputSomething()
        {
            cout << "Parent::OutputSomething" << endl;
        }
    };

    class Child : public Parent
    {
    private:
    public:
        Child();
        ~Child();
        void OutputSomething();
    };

} // namespace extend_class