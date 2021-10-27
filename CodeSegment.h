#ifndef CODESEGMENT_H
#define CODESEGMENT_H

#include <QString>



class CodeSegment
{
public:
    CodeSegment();
    static void testMem();
    static void testArrayInit();

    static QString Uuid();
};

#endif // CODESEGMENT_H
