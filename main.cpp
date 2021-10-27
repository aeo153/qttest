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

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    TestCases tc;
//    tc.testInitStruct();

    std::cout<<__func__<<std::endl;
    TestStd stdtest;
//    stdtest.testMove();
    stdtest.test_map();
    stdtest.test_unordered_map();

//    QtTest qtTst;
//    qtTst.WriteXML();

//    TestTemplate<int> tmplTest;
//    tmplTest.print(2, 3);

//    TemplateFun::TmplFun<int>(3, 6);

    //CodeSegment::testArrayInit();

//    ClassA a1;
//    ClassA a2(2);
//    ClassA a3(a2);
////    ClassA a4 = a2;

    //return a.exec();
    return getchar();
}
