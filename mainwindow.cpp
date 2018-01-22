#include "ArrayPtr.h"
#include "mainwindow.h"
#include "threadtest.h"
#include "ui_mainwindow.h"
#include <QCheckBox>
#include <QMessageBox>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QSequentialAnimationGroup>
#include <plot/CurvePlot.h>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>
#include <math.h>
#include <qmath.h>

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

    /************************Animation*******************/
    QMenu * animationMenu = new QMenu("Animation", this);
    mnBar->addMenu(animationMenu);

    QAction * pAct = new QAction("Button", animationMenu);
    connect(pAct, &QAction::triggered, this, &MainWindow::onAnimationBtn);
    animationMenu->addAction(pAct);    

    m_animation = new QPropertyAnimation(this, "geometry");

    /************************UITest*******************/
    QMenu * uiTestMenu = new QMenu("UITest", this);
    mnBar->addMenu(uiTestMenu);

    pAct = new QAction("TwoPlace", uiTestMenu);
    connect(pAct, &QAction::triggered, this, &MainWindow::onTestTwoPlaceWdt);
    uiTestMenu->addAction(pAct);    

    pAct = new QAction("ChildObject", uiTestMenu);
    connect(pAct, &QAction::triggered, this, &MainWindow::onTestChildObject);
    uiTestMenu->addAction(pAct);

    /************************AlgTest*******************/
    QMenu * algTestMenu = new QMenu("AlgTest", this);
    mnBar->addMenu(algTestMenu);

    pAct = new QAction("ArrayPtr", algTestMenu);
    connect(pAct, &QAction::triggered, this, &MainWindow::onTestArrayPtr);
    algTestMenu->addAction(pAct);

    pAct = new QAction("Thread", algTestMenu);
    connect(pAct, &QAction::triggered, this, &MainWindow::onTestThread);
    algTestMenu->addAction(pAct);
}

void MainWindow::testTreeWidget()
{
    //    QStringList colText;
    //    colText<<"col1"<<"";
    //    QTreeWidgetItem * pPItem = new QTreeWidgetItem(colText);
    //    ui->treeWidget->setColumnWidth(0, 220);
    //    ui->treeWidget->setColumnWidth(1, 20);
    //    ui->treeWidget->addTopLevelItem(pPItem);
    //    ui->treeWidget->setItemWidget(pPItem, 1, new QCheckBox(ui->treeWidget));

    //    colText.clear();
    //    colText<<"col3";
    //    QTreeWidgetItem * pPItem2 = new QTreeWidgetItem(colText);
    //    colText.clear();
    //    colText<<"col4"<<"col5";
    //    QTreeWidgetItem * pSItem2 = new QTreeWidgetItem(pPItem2, colText);
    //    pPItem2->addChild(pSItem2);

    //    ui->treeWidget->addTopLevelItem(pPItem2);
}

void MainWindow::onAddResult(int result)
{
    qDebug()<<__func__<<":"<<result;
    delete m_addTest;
}

void MainWindow::testCurvePlot()
{
    CurvePlotFrm * plot = new CurvePlotFrm(this);
    setCentralWidget(plot);

    //计算曲线数据
    std::vector<double> xs;
    std::vector<double> ys;

    for (double x = 0; x <= 300; x += 0.1)
    {
        xs.push_back(x);
        ys.push_back(50 + 100 * qSin(x));
    }

    plot->AddCurveData("liver", xs, ys);
}

void MainWindow::onTestTwoPlaceWdt()
{
    m_twoPlaceLbl = new QLabel(this);
    m_twoPlaceLbl->setText("test two place widget");
    setCentralWidget(m_twoPlaceLbl);

    QDialog dlg(this);
    QVBoxLayout * dlgLyt = new QVBoxLayout(&dlg);
    dlgLyt->addWidget(m_twoPlaceLbl);
    dlg.resize(400, 500);
    dlg.exec();
}

void MainWindow::onTestChildObject()
{
    QGroupBox * grpBox = new QGroupBox(this);
    QHBoxLayout * hLyt = new QHBoxLayout(grpBox);
    QLabel * pLbl1 = new QLabel("lbl1", grpBox);
    hLyt->addWidget(pLbl1);

    QLabel * pLbl2 = new QLabel("lbl2", grpBox);
    hLyt->addWidget(pLbl2);

    QLabel * pLbl3 = new QLabel("lbl3", grpBox);
    hLyt->addWidget(pLbl3);

    connect(pLbl1, &QObject::destroyed, this, &MainWindow::onObjectDestroyed);
    connect(pLbl2, &QObject::destroyed, this, &MainWindow::onObjectDestroyed);
    connect(pLbl3, &QObject::destroyed, this, &MainWindow::onObjectDestroyed);
    connect(grpBox, &QObject::destroyed, this, &MainWindow::onObjectDestroyed);
    setCentralWidget(grpBox);

    //pLbl1->setParent(nullptr);
    //pLbl2->setParent(nullptr);
    //pLbl3->setParent(nullptr);
    //delete grpBox;//pLbl1,pLbl2不会销毁, pLbl3,grpBox会销毁
    //delete hLyt;//单删除layout,widget不会被删除
}

void MainWindow::onTestArrayPtr()
{
    int num = 1e6;
    int * pArr = new int[num];
    ArrayPtr<int> arrPtr(pArr);
//    ArrayPtr<int> arrPtr(num);
//    auto pArr = arrPtr.GetPointer();
    for ( int i = 0; i < num; i++ )
    {
        pArr[i] = i;
    }

    for ( int i = 0; i < num; i++ )
    {
        qDebug()<<__func__<<" "<<pArr[i];
    }
}

void MainWindow::onTestThread()
{
    m_addTest = new ThreadTest;
    std::function<void (int)> fun = std::bind(&MainWindow::onAddResult, this, std::placeholders::_1);
    m_addTest->SetResultFun(fun);
    m_addTest->Add(100, 200);
}

void MainWindow::onObjectDestroyed()
{
    QObject * pObj = sender();
    qDebug()<<__func__<< pObj->metaObject()->className();
}
