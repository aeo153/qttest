#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QPushButton>
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

    QStringList colText;
    colText<<"col1";
    QTreeWidgetItem * pPItem = new QTreeWidgetItem(colText);
    colText.clear();
    colText<<"col2";
    QTreeWidgetItem * pSItem = new QTreeWidgetItem(pPItem, colText);
    pPItem->addChild(pSItem);
    ui->treeWidget->addTopLevelItem(pPItem);

    colText.clear();
    colText<<"col3";
    QTreeWidgetItem * pPItem2 = new QTreeWidgetItem(colText);
    colText.clear();
    colText<<"col4";
    QTreeWidgetItem * pSItem2 = new QTreeWidgetItem(pPItem2, colText);
    pPItem2->addChild(pSItem2);

    colText.clear();
    colText<<"col5";
    QTreeWidgetItem * pSItem3 = new QTreeWidgetItem(pSItem2, colText);
    pSItem2->addChild(pSItem3);

    ui->treeWidget->addTopLevelItem(pPItem2);
}
