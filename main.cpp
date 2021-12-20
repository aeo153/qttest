#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "testcases.h"
#include "teststd.h"
#include "templatetest.cpp"
#include "qttest.h"
#include <iostream>
#include "ClassA.h"
#include "CodeSegment.h"
#include "UtilsDef.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    std::locale::global(std::locale(""));
    std::setlocale(LC_CTYPE, "");
    std::wcout.imbue(std::locale(""));
//    TestCases tc;
//    tc.testInitStruct();

//    TestStd stdtst;
//    stdtst.iterator();

    std::cout<<RED     <<"Hello, World! in RED\n";
    std::cout<<GREEN    <<"Hello, World! in GREEN\n";
    std::cout<<YELLOW   <<"Hello, World! in YELLOW\n";
    std::cout<<BLUE     <<"Hello, World! in BLUE\n";
    std::cout<<MAGENTA  <<"Hello, World! in MAGENTA\n";
    std::cout<<CYAN     <<"Hello, World! in CYAN\n";
    std::cout<<WHITE    <<"Hello, World! in WHITE\n";
    std::cout<<BOLDRED  <<"Hello, World! in BOLDRED\n";
    std::cout<<BOLDCYAN <<"Hello, World! in BOLDCYAN\n";

//    TestTemplate<int> tmplTest;
//    tmplTest.print(2, 3);

//    TemplateFun::TmplFun<int>(3, 6);

    //qDebug()<<CodeSegment::Uuid();
    //CodeSegment::testConstexpr();

    //return a.exec();
    return getchar();
}
