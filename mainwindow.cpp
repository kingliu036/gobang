#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ctlboard.h"
#include <QPainter>
#include<QPixmap>
#include<QPaintEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerId = startTimer(10);               //刷新棋盘
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter qp(this);
    QPixmap board(":/board.png");                   //板面背景
    QPixmap black(":/black.jpg");                   //黑白子
    QPixmap white(":/white.jpg");
    qp.drawPixmap(0,0,1200,800,board);
    QFont font2("宋体",20,QFont::Bold,true);
    qp.setFont(font2);
    qp.drawText(900,100,"XPOS:");                   //点击位置
    qp.drawText(900,300,"YPOS:");
    QString string1=QString::number(nowx);
    QString string2=QString::number(nowy);
    qp.drawText(1050,100,string1);
    qp.drawText(1050,300,string2);
    if(player==1)
    {
        qp.drawText(900,500,"玩家走棋");
    }
    else if(player==-1)
    {
        qp.drawText(900,500,"电脑走棋");
    }
    for(int i=0;i<15;i++)                               //画出棋子
    {
        for(int j=0;j<15;j++)
        {
            if(pos[i][j]==1)
            {
                qp.drawPixmap(j*54,i*54,48,48,black);
            }
            else if(pos[i][j]==-1)
            {
                qp.drawPixmap(j*54,i*54,48,48,white);
            }
        }
    }
    qp.setPen(Qt::red);
    if(check()==1)
    {
        qp.drawText(900,700,"玩家胜利!");
    }
    else if(check()==-1)
    {
        QFont font3("宋体",12,QFont::Bold,true);
        qp.setFont(font3);
        qp.drawText(850,700,"你还玩不过人工智障!!!");
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int mx = event->x();                            //获取鼠标点击的位置
    int my = event->y();
    for(int i=1;i<=15;i++)
    {
        if(mx<i*53.3)
        {
            nowx=i;
            break;
        }
    }
    for(int i=0;i<15;i++)
    {
        if(my<i*53.3)
        {
            nowy=i;
            break;
        }
    }
    pos[nowy-1][nowx-1]=1;
    player=1;
    controller.react(pos,player);
}


void MainWindow::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    int id = e->timerId();
    if(id==timerId)
    {
        repaint();
    }
}

int MainWindow::check()                         //检查游戏是否结束
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(pos[i][j]==pos[i][j+1]&&pos[i][j]==pos[i][j+2]&&pos[i][j]==pos[i][j+3]&&pos[i][j]==pos[i][j+4])
            {
                if(pos[i][j]==1)
                {
                    return 1;
                }
                else if(pos[i][j]==-1)
                {
                    return -1;
                }

            }
            if(pos[i][j]==pos[i+1][j]&&pos[i][j]==pos[i+2][j]&&pos[i][j]==pos[i+3][j]&&pos[i][j]==pos[i+4][j])
            {
                if(pos[i][j]==1)
                {
                    return 1;
                }
                else if(pos[i][j]==-1)
                {
                    return -1;
                }
            }
            if(pos[i][j]==pos[i+1][j+1]&&pos[i][j]==pos[i+2][j+2]&&pos[i][j]==pos[i+3][j+3]&&pos[i][j]==pos[i+4][j+4])
            {
                if(pos[i][j]==1)
                {
                    return 1;
                }
                else if(pos[i][j]==-1)
                {
                    return -1;
                }
            }
            if(pos[i][j]==pos[i+1][j-1]&&pos[i][j]==pos[i+2][j-2]&&pos[i][j]==pos[i+3][j-3]&&pos[i][j]==pos[i+4][j-4])
            {
                if(pos[i][j]==1)
                {
                    return 1;
                }
                else if(pos[i][j]==-1)
                {
                    return -1;
                }
            }
        }
    }
    return 2;
}
















