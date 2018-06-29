#ifndef TESTCASES_H
#define TESTCASES_H
#include <string>

struct STest
{
    int a;
    float b;
    std::string c;
};

class TestCases
{
public:
    explicit TestCases();
    ~TestCases();

    void getDirvers();

    void testEmptyString();

    void testDB();

    void testDate();

    void testProcess();

    void testArrayPtr();

    //auto getValue() { return 1.4; }

    void testInitStruct();
};

#endif // TESTCASES_H
