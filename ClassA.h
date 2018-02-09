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
    ClassA();

    float add(const float & a, const float & b) { return a + b; }

    void printSelf();
};

#endif // CLASSA_H
