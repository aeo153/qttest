#include "testcases.h"

#include <QString>
#include <QDebug>
#include <QDir>
#include <windows.h>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QApplication>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QPushButton>
#include "ComplieTime.h"
#include "ArrayPtr.h"
#include <iostream>

TestCases::TestCases()
{

}

TestCases::~TestCases()
{

}

quint64 getDiskFreeSpace(QString driver)
{
    LPCWSTR lpcwstrDriver=(LPCWSTR)driver.utf16();
    ULARGE_INTEGER liFreeBytesAvailable, liTotalBytes, liTotalFreeBytes;
    if( !GetDiskFreeSpaceEx(lpcwstrDriver, &liFreeBytesAvailable, &liTotalBytes, &liTotalFreeBytes) )
    {
        qDebug() << "ERROR: Call to GetDiskFreeSpaceEx() failed.";
        return 0;
    }
    return (quint64) liTotalFreeBytes.QuadPart/1024/1024/1024;
}


void TestCases::getDirvers()
{
      auto driversList = QDir::drives();
      for(const auto & fileInfo : driversList )
      {
          qDebug()<<fileInfo.absoluteFilePath()<<getDiskFreeSpace(fileInfo.absoluteFilePath());
      }
}

void TestCases::testEmptyString()
{
    QString txt;
    bool bOk;
    int num = txt.toInt(&bOk);
    qDebug()<< "empty string to int:"<<bOk<<" value:"<<num;

    bOk = true;
    double dbl = txt.toDouble(&bOk);
    qDebug()<< "empty string to double:"<<bOk<<" value:"<<dbl;
}

void TestCases::testDB()
{
    QSqlDatabase dbConn = QSqlDatabase::addDatabase("QSQLITE");
    QString appdir = qApp->applicationDirPath();
    dbConn.setDatabaseName(appdir + "/db/dsyx.db");
    if ( !dbConn.open() )
    {
        qDebug()<<"failed create db";
    }

    QSqlQuery query(dbConn);
    query.exec("create table Privilege(PCode int not null, Description varchar(255), primary key (PCode));");
}

void TestCases::testDate()
{
    qDebug()<<GetBuildTime();
}

void TestCases::testProcess()
{
    //Libtest lt;
    //int a = lt.Add(10 , 20);
    //QMessageBox::information(this, tr("libtest"), tr("Add:%1").arg(a));

    //QProcess::startDetached(tr("/home/tands/Program/qt/5.8/gcc_64/bin/assistant"));
}

void TestCases::testArrayPtr()
{
    int num = 1e6;
    int * pArr = new int[num];
    ArrayPtr<int> arrPtr(pArr);
    for ( int i = 0; i < num; i++ )
    {
        pArr[i] = i;
    }

    for ( int i = 0; i < num; i++ )
    {
        qDebug()<<__func__<<" "<<pArr[i];
    }
}

void TestCases::testInitStruct()
{
    STest s1{1, 2.0f, "s1"};
    STest s2{2, 3.0f, "s2"};
    STest s3{3, 4.0f, "s3"};
    s3 = {3, 5.0f, "s4"};
    auto printSTest = [&](const STest & tst)
    {
        std::cout<<tst.a<<","<<tst.b<<","<<tst.c<<std::endl;
    };

    printSTest(s1);
    printSTest(s2);
    printSTest(s3);

    //std::cout<<__func__<<sizeof(std::string)<<" "<<sizeof(float)<<std::endl;
}
