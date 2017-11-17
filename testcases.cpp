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

void TestCases::testAnimation()
{
    QPushButton button("Animated Button");
    button.show();

    QPropertyAnimation animation(&button, "geometry");
    animation.setDuration(3000);
    animation.setStartValue(QRect(0, 0, 100, 30));
    animation.setEndValue(QRect(250, 250, 100, 30));

    animation.setEasingCurve(QEasingCurve::OutBounce);

    animation.start();
    /*
    QPushButton *bonnie = new QPushButton("Bonnie");
    bonnie->show();

    QPushButton *clyde = new QPushButton("Clyde");
    clyde->show();

    // 动画一
    QPropertyAnimation *anim1 = new QPropertyAnimation(bonnie, "geometry");

    // 动画二
    QPropertyAnimation *anim2 = new QPropertyAnimation(clyde, "geometry");

    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(anim1);
    group->addAnimation(anim2);

    group->start();*/
}
