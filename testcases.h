#ifndef TESTCASES_H
#define TESTCASES_H


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

    auto getValue() { return 1.4; }
};

#endif // TESTCASES_H
