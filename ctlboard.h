#ifndef CTLBOARD_H
#define CTLBOARD_H
#include<iostream>
#include<QString>
const int INF = 10000;
class ctlboard
{
public:
    ctlboard();
    int board[15][15];
    int value;
    void switchplayer(int player);
    int get_value(int board[20][20]);
    int get_reverse_value(int board[20][20]);
    int Min_Value(int board[20][20]);
    int Max_Value(int board[20][20]);
    void react(int board[20][20],int player);
    void result(int flag,int board[20][20]);
private:

};

#endif // CTLBOARD_H
