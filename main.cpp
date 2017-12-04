#include "mainwindow.h"
#include <QApplication>

#include "testcases.h"
#include "teststd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.testCurvePlot();
    w.show();


//    TestCases tc;
//    tc.testDate();

//    TestStd stdtest;
//    stdtest.testStringStream();

    return a.exec();
}
