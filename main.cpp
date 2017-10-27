#include "mainwindow.h"
#include <QApplication>

#include "testcases.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();


    TestCases tc;
    tc.testEmptyString();
    tc.getDirvers();

    return a.exec();
}
