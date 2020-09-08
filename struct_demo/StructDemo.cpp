/*
 * @Author: wangxuguang 
 * @Date: 2020-09-07 09:32:24 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-07 10:12:02
 */
#include "StructDemo.h"

void StructDemo::test()
{
    struct PersonInfo
    {
        int index;
        char name[30];
        short age;
    } Person[5] =
        {{1, "张三", 20}, {2, "李四", 21}, {3, "王五", 22}, {4, "算是", 23}, {5, "仍然", 24}};

    struct PersonInfo *pPersonInfo;
    pPersonInfo = Person;
    for (int i = 0; i < 5; i++, pPersonInfo++)
    {
        cout << pPersonInfo->index << ", " << pPersonInfo->name << ", " << pPersonInfo->age << endl;
    }
}
