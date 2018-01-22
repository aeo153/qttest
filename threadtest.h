#ifndef THREADTEST_H
#define THREADTEST_H
#include <thread>

class ThreadTest
{
public:
    ThreadTest();
    ~ThreadTest();
    void Add(int a, int b);

    void DoAdd(int a, int b);
    void SetResultFun(std::function<void (int)> & resultFun);

private:
    std::thread * m_thread = nullptr;

    std::function<void (int)> m_resultFun;
};

#endif
