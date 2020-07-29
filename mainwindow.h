#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QPixmap>
#include<QPaintEvent>
#include"ctlboard.h"
#include<queue>
#include"node.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int pos[20][20]={{0}};

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *);
    int check();
    int nowx=0,nowy=0;
private:
    Ui::MainWindow *ui;
    int timerId;
    int player=1;
    ctlboard controller;
};
#endif // MAINWINDOW_H
