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

//    TestStd stdtest;
//    stdtest.testRandomNumber();
//    stdtest.testRandomNumber();
//    stdtest.testRandomNumber();
    //QtTest qtTst;
    //qtTst.testRegular();
   // TestStd stdtest;
//    stdtest.testMove();
//    stdtest.test_map();
//    stdtest.test_unordered_map();
    //stdtest.splitString();

//    TestTemplate<int> tmplTest;
//    tmplTest.print(2, 3);

//    TemplateFun::TmplFun<int>(3, 6);

    //qDebug()<<CodeSegment::Uuid();
    CodeSegment::SprintfTest();

    //return a.exec();
    return getchar();
}
