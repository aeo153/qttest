#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "testcases.h"
#include "teststd.h"

auto getValue() { return 1.4; }

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.testCurvePlot();
//    w.show();
//    auto dVal = getValue();
//    qDebug()<<dVal;


//    TestCases tc;
//    tc.testDate();

    TestStd stdtest;
    stdtest.testTuple();

    return a.exec();
}
