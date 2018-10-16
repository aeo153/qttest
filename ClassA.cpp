#include "ClassA.h"
#include <QMessageBox>
#include <iostream>
#include <QDebug>

ClassA::ClassA()
{
    qDebug()<<__FUNCTION__;
}

ClassA::ClassA(int num)
    :m_number(num)
{
    qDebug()<<"ClassA(int num)";
}

ClassA::ClassA(const ClassA &other)
{
    m_number = other.m_number;
    qDebug()<<"ClassA(const ClassA &other)";
}

void ClassA::printSelf()
{
    std::cout<<__func__<<std::endl;
}

float Functor::operator()(const float & a, const float & b) const
{
    return a + b;
}
