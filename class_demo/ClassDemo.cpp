/*
 * @Author: wangxuguang 
 * @Date: 2020-09-08 11:33:29 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2020-09-08 14:35:21
 */
#include <iostream>
#include "ClassDemo.h"

class CItem
{
    /// 声明友元函数，在函数调用范围内，可以访问声明友元函数的类成员变量；
    friend void CList::OutputItem();

private:
    char m_Name[128];
    void OutputName()
    {
        std::cout << m_Name << std::endl;
    }

public:
    void SetItemName(const char *pchData)
    {
        if (pchData != NULL)
        {
            strcpy(m_Name, pchData);
        }
    }
    CItem() 
    {
        memset(m_Name, 0, 128);
    }
};

void CList::OutputItem()
{
    m_pItem->SetItemName("西安");
    
    /// 可以调用到友元函数声明类的私有方法
    m_pItem->OutputName();
}

CList::CList()
{
    m_pItem = new CItem();
}

CList::~CList()
{
    delete m_pItem;
    m_pItem = NULL;
}