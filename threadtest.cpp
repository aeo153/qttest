#include "threadtest.h"

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
    m_resultFun(c);
}

void ThreadTest::SetResultFun(std::function<void (int)> &resultFun)
{
    m_resultFun = resultFun;
}
