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

public slots:
    void onAnimationBtn();

private:
    void initUI();

private:
    Ui::MainWindow *ui;
    class QPropertyAnimation * m_animation;
};

#endif // MAINWINDOW_H
