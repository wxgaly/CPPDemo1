/*
 * @Author: Gary Wang
 * @Date: 2020-09-16 16:17:50
 * @LastEditors: Gary Wang
 * @LastEditTime: 2020-09-17 15:59:47
 * @Description: file content
 */
#include "FileDemo.h"

void BinatyFileDemo::test()
{
    string filename = "test.bin";
    char buf[50];
    fstream file;
    file.open(filename, ios::binary | ios::out);
    for (size_t i = 0; i < 2; i++)
    {
        memset(buf, 0, 50);
        cin >> buf;
        file.write(buf, 50);
        file << endl;
    }
    file.close();

    file.open(filename, ios::binary | ios::in);
    while (!file.eof())
    {
        memset(buf, 0, 50);
        file.read(buf, 50);
        if (file.tellg() > 0)
        {
            cout << buf;
        }
    }
    cout << endl;
    file.close();
}

/*
* 读写文件
*/
void RWFileDemo::test()
{
    string filename = "testrw.txt";
    ofstream ofile;
    ofile.open(filename);
    char buf[128];

    memset(buf, 0, 128);
    cin >> buf;
    ofile << buf;
    ofile.close();

    ifstream ifile(filename);
    while (!ifile.eof())
    {
        char ch;
        ifile.get(ch);
        if (!ifile.eof())
        {
            cout << ch;
        }
    }
    cout << endl;
    ifile.close();
}

/*
* 创建文件
*/
void CraeteFileDemo::test()
{
    ofstream ofile;
    ofile.open("test.txt");
    if (!ofile.fail())
    {
        ofile << "这是"
              << " ";
        ofile << "一行文字" << endl;
        ofile << "回车?";
        ofile.close();
    }
}
