#include "testcases.h"

#include <QString>
#include <QDebug>
#include <QDir>
#include <windows.h>

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
 if( !GetDiskFreeSpaceEx( lpcwstrDriver, &liFreeBytesAvailable, &liTotalBytes, &liTotalFreeBytes) )
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
    qDebug()<< "empty string to int:"<<bOk;

    bOk = true;
    double dbl = txt.toDouble(&bOk);
    qDebug()<< "empty string to double:"<<bOk;
}
