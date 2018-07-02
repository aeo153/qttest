#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "testcases.h"
#include "teststd.h"
#include "templatetest.cpp"
#include "qttest.h"
#include <iostream>
#include "CodeSegment.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    TestCases tc;
//    tc.testInitStruct();

    //TestStd stdtest;
    //stdtest.createfun();

//    QtTest qtTst;
//    qtTst.WriteXML();

    TestTemplate<int> tmplTest;
    tmplTest.print(2, 3);

//    TemplateFun::TmplFun<int>(3, 6);

    //CodeSegment::testMem();


    //return a.exec();
    return 0;
}
