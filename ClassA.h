#ifndef CLASSA_H
#define CLASSA_H

class Functor
{
public:
    float operator()(const float & a, const float & b) const;
};

class ClassA
{
public:
    explicit ClassA();
    explicit ClassA(int num);
    explicit ClassA(const ClassA & other);


    float add(const float & a, const float & b) { return a + b; }

    void printSelf();

    ClassA & operator=(const ClassA & other)
    {
        m_number = other.m_number;
        return *this;
    }

private:
    int m_number{0};
};

#endif // CLASSA_H
