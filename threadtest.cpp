#include "threadtest.h"
#include <iostream>
#include <QDebug>

ThreadTest::ThreadTest()
{

}

ThreadTest::~ThreadTest()
{
    if ( m_thread )
    {
        delete m_thread;
        m_thread = nullptr;
    }
}

void ThreadTest::Add(int a, int b)
{
    m_thread = new std::thread(&ThreadTest::DoAdd, this, a, b);
    m_thread->detach();
}

void ThreadTest::DoAdd(int a, int b)
{
    int c =  a + b;
    std::cout<<__func__<<std::this_thread::get_id();
    for (int i = 0; i < 1e10; i++ )
    {
        c = a + b;
        qDebug()<<i<<";"<<"a + b = "<< c;
    }
    m_resultFun(c);
}

void ThreadTest::SetResultFun(std::function<void (int)> &resultFun)
{
    m_resultFun = resultFun;
}
