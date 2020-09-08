/*
 * @Author: wangxuguang 
 * @Date: 2020-09-08 18:11:24 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-08 18:21:27
 */
#include "ExtendClassDemo.h"

extend_class::Child::Child()
{
    cout << "Child::create" << endl;
}

extend_class::Child::~Child()
{
    cout << "Child::delete" << endl;
}

/// 覆写父类方法
void extend_class::Child::OutputSomething()
{
    cout << "Child::OutputSomething" << endl;
}