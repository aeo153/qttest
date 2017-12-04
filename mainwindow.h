#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void testCurvePlot();

public slots:
    void onAnimationBtn();

private:
    void initUI();
    void testTreeWidget();

private:
    Ui::MainWindow *ui;
    class QPropertyAnimation * m_animation;
};

#endif // MAINWINDOW_H
