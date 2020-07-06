#ifndef TESTSTD_H
#define TESTSTD_H

#include <functional>
#include <vector>

enum E_ColorType
{
    e_red = 0,
    e_green,
    e_blue,
    e_black,
    e_white
};

class TestStd
{
public:
    TestStd();

public:
    void testList();

    void testVector();

    void TestCopy();

    void testStringStream();

    void testTypeId();

    void testTuple();

    void checkFileExists();

    void testMemory();

    void testErase();

    void createfun();
    void execFun(const std::vector<std::function< float (const float &, const float &)> > funs);

    void testNumericLimits();

    void timeClock();

    void testCustomData();

    void regularExpression();
};

#endif // TESTSTD_H
