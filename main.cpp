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
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    TestCases tc;
//    tc.testInitStruct();

    TestStd stdtest;
    stdtest.regularExpression();

    QtTest qtTst;
    qtTst.testRegular();

//    TestTemplate<int> tmplTest;
//    tmplTest.print(2, 3);

//    TemplateFun::TmplFun<int>(3, 6);

    //qDebug()<<CodeSegment::Uuid();

    //return a.exec();
    return getchar();
}
