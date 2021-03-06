/*
 * @Author: wangxuguang 
 * @Date: 2020-09-10 18:51:47 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-11 11:42:08
 */
#include "stl_demo.h"
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>

void ForEachDemo::test()
{
    int arr[8] = {1, 2, 2, 2, 5, 6, 6, 7};
    vector<int> vector1(arr, arr + 8);
    for_each(vector1.begin(), vector1.end(), [&](int val) { cout << val << " "; });
    cout << endl;
    // fill(vector1.begin(), vector1.end(), 1);
    // for_each(vector1.begin(), vector1.end(), [&](int val) { cout << val << " "; });
    // cout << endl;
    rotate(vector1.begin(), vector1.begin() + 4, vector1.end());
    for_each(vector1.begin(), vector1.end(), [&](int val) { cout << val << " "; });
    cout << endl;
}

void CountDemo::test()
{
    int arr[8] = {1, 2, 2, 2, 5, 6, 6, 7};
    vector<int> vector1(arr, arr + 8);
    int res = count(vector1.begin(), vector1.end(), 2);
    cout << "2的个数: " << res << endl;
    res = count(vector1.begin(), vector1.end(), 6);
    cout << "6的个数: " << res << endl;
}

void AdjacentFindDemo::test()
{
    int arr[8] = {1, 2, 2, 4, 5, 6, 6, 7};
    vector<int> vector1(arr, arr + 8);
    vector<int>::iterator it;
    it = adjacent_find(vector1.begin(), vector1.end());
    cout << *it++ << " " << *it << endl;
    it = adjacent_find(it, vector1.end());
    cout << *it++ << " " << *it << endl;
}

/*
* 多行注释
* ？？
*/
void MapDemo::test()
{
    map<int, char> cMap;
    cMap[1] = 'A';
    cMap[2] = 'B';
    cMap[3] = 'C';
    cMap[4] = 'D';
    cMap[5] = 'E';
    cMap[6] = 'F';
    map<int, char>::iterator it;
    for (it = cMap.begin(); it != cMap.end(); it++)
    {
        cout << (*it).first << "->";
        cout << (*it).second << endl;
    }
    //测试查找
    it = cMap.find(5);
    if (it != cMap.end())
    {
        cout << (*it).first << ":" << (*it).second << endl;
    }
    else
    {
        cout << "not found 5" << endl;
    }

    //map特性
    cout << cMap[2] << endl;
}

void SetDemo::test()
{
    set<int> intset;
    intset.insert(9);
    intset.insert(23);
    intset.insert(3);
    intset.insert(6);
    intset.insert(30);
    intset.insert(17);
    intset.insert(17); //添加重复元素
    printIterator("set", intset.begin(), intset.end());
    intset.erase(17);
    printIterator("set", intset.begin(), intset.end());

    set<int>::iterator it = intset.find(30);
    if (it == intset.end()) //不等于end即为找到元素
    {
        cout << "not find 30" << endl;
    }
    else
    {
        cout << "find 30" << endl;
    }
    it = intset.find(31);

    if (it == intset.end())
    {
        cout << "not find 31" << endl;
    }
}

void ListDemo::test()
{
    int array[10] = {9, 3, 7, 8, 6, 4, 5, 0, 2, 1};
    list<int> list(array, array + 10);
    printIterator("排序前list", list.begin(), list.end());
    list.sort();
    printIterator("排序后list", list.begin(), list.end());
}

void DequeDemo::test()
{
    deque<int> intdeque;
    intdeque.push_back(1);
    intdeque.push_back(2);
    intdeque.push_back(3);
    intdeque.push_back(4);
    intdeque.push_back(5);
    printIterator("intdeque", intdeque.begin(), intdeque.end());

    cout << "intdeque.pop_front(): " << endl;
    intdeque.pop_front();
    printIterator("intdeque", intdeque.begin(), intdeque.end());
}

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
    printIterator(name, v.begin(), v.end());
}