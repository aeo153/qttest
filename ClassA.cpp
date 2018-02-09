#include "ClassA.h"
#include <QMessageBox>
#include <iostream>

ClassA::ClassA()
{

}

void ClassA::printSelf()
{
    std::cout<<__func__<<std::endl;
}

float Functor::operator()(const float & a, const float & b) const
{
    return a + b;
}
