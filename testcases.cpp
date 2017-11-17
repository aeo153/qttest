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
