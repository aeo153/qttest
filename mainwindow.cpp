#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "libtest.h"
#include <QMessageBox>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Libtest lt;
    //int a = lt.Add(10 , 20);
    //QMessageBox::information(this, tr("libtest"), tr("Add:%1").arg(a));

    //QProcess::startDetached(tr("/home/tands/Program/qt/5.8/gcc_64/bin/assistant"));
}
