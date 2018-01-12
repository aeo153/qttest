#ifndef TEMPLATETEST_H
#define TEMPLATETEST_H

template<class T>
class TestTemplate
{
public:
    TestTemplate() {};
    ~TestTemplate() {};
    T add_base(T x,T y);
    void print(T x,T y);
};

class TemplateFun
{
public:
    TemplateFun() {}
    ~TemplateFun() {}

    template<class T>
    static void TmplFun(T x, T y);
};


#endif
