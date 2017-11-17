#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "libtest.h"
#include <QMessageBox>
#include <QParallelAnimationGroup>
#include <QProcess>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
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

void MainWindow::onAnimationBtn()
{
//    m_animation->setTargetObject(ui->pushButton);
//    m_animation->setDuration(6000);
//    m_animation->setStartValue(QRect(0, 0, 100, 30));
//    m_animation->setEndValue(QRect(250, 250, 100, 30));

//    m_animation->setEasingCurve(QEasingCurve::OutBounce);

//    m_animation->start();

    QPushButton *bonnie = new QPushButton("Bonnie");
    bonnie->show();

    QPushButton *clyde = new QPushButton("Clyde");
    clyde->show();

    // 动画一
    QPropertyAnimation *anim1 = new QPropertyAnimation(bonnie, "geometry");
    anim1->setDuration(6000);
    anim1->setStartValue(QRect(0, 0, 100, 30));
    anim1->setEndValue(QRect(250, 250, 100, 30));

    anim1->setEasingCurve(QEasingCurve::OutBounce);

    // 动画二
    QPropertyAnimation *anim2 = new QPropertyAnimation(clyde, "geometry");
    anim2->setDuration(6000);
    anim2->setStartValue(QRect(600, 0, 100, 30));
    anim2->setEndValue(QRect(250, 250, 100, 30));

    anim2->setEasingCurve(QEasingCurve::OutBounce);

    //QParallelAnimationGroup
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
    group->addAnimation(anim1);
    group->addAnimation(anim2);

    group->start();
}

void MainWindow::initUI()
{
    QMenuBar * mnBar = menuBar();
    QMenu * animationMenu = new QMenu("Animation", this);

    QAction * pAct = new QAction("Button", animationMenu);
    connect(pAct, &QAction::triggered, this, &MainWindow::onAnimationBtn);
    animationMenu->addAction(pAct);
    mnBar->addMenu(animationMenu);

    m_animation = new QPropertyAnimation(this, "geometry");
}
