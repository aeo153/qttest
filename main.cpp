#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "testcases.h"
#include "teststd.h"
#include "templatetest.cpp"
#include <iostream>



int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    TestCases tc;
//    tc.testArrayPtr();

    TestStd stdtest;
    stdtest.testErase();

//    TestTemplate<int> tmplTest;
//    tmplTest.print(2, 3);

//    TemplateFun::TmplFun<int>(3, 6);


    //return a.exec();
    return 0;
}
