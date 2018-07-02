#include "templatetest.h"
#include <iostream>

template<class T>
T TestTemplate<T>::add_base(T x,T y)
{
    return x+y;
}

template<class T>
void TestTemplate<T>::print(T x,T y)
{
    auto val = add_base(x, y);
    std::cout<<__func__<<" "<<val<<std::endl;
}

//template<class T>
//void TemplateFun::TmplFun(TemplateFun::T x, TemplateFun::T y)
//{
//    auto val = x + y;
//    std::cout<<__func__<<" "<<val<<std::endl;
//}
