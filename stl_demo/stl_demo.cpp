/*
 * @Author: wangxuguang 
 * @Date: 2020-09-10 18:51:47 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-11 10:29:12
 */
#include "stl_demo.h"
#include <vector>

void VectorDemo::test()
{
    vector<int> v1, v2;
    v1.resize(10);
    v2.resize(10);

    v1 = vector<int>(8, 7);
    int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    v2 = vector<int>(array, array + 8);

    cout << "v1容量: " << v1.capacity() << endl;
    cout << "v1当前各项: " << endl;
    printVector("v1", v1);
    cout << "v2当前各项: " << endl;
    printVector("v2", v2);
    cout << "v2.push_back(9): " << endl;
    v2.push_back(9);
    printVector("v2", v2);
    cout << "v2.erase(v2.end() - 2): " << endl;
    v2.erase(v2.end() - 2);
    printVector("v2", v2);
    cout << "v2.pop_back(): " << endl;
    v2.pop_back();
    printVector("v2", v2);
    cout << "v1.swap(v2): " << endl;
    v1.swap(v2);
    printVector("v1", v1);
    printVector("v2", v2);
}

void printVector(const string &name, vector<int> &v)
{
    cout << name << ":";
    for (decltype(v.size()) i = 0; i < v.size(); i++)
    {
        cout << " " << v[i];
    }
    cout << endl;
}