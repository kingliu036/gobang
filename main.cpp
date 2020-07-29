#include "mainwindow.h"
#include<QMediaPlayer>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/hdl.mp3"));                 //播放音乐；
    player->setVolume(30);
    player->play();*/
    w.show();
    w.setWindowTitle("人工智障");
    w.resize(1200,800);
    return a.exec();
}
