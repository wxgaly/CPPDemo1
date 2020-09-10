/*
 * @Author: wangxuguang 
 * @Date: 2020-09-10 18:51:47 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-10 21:59:45
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

    for (decltype(v2.size()) i = 0; i < v1.size(); i++)
    {
        cout << " " << v1[i];
    }

    cout << endl;
}