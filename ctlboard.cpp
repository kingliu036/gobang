#include "ctlboard.h"
#include<iostream>
#include<QString>
using namespace std;
ctlboard::ctlboard()
{

}

void ctlboard::switchplayer(int player)             //交换玩家
{
    player=-player;
}

int ctlboard::get_value(int (*board)[20])           //计算人类盘面价值
{
    int maxvalue=0;
    int tempvalue=0;
    int count=0;
    bool start=false;
    bool before=false;
    int row_col_dia[90][20]={{0}};
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            row_col_dia[i][j]=board[i][j];
            row_col_dia[i+15][j]=board[j][i];
            if(i+j<15)
            {
                row_col_dia[i+30][j]=board[j][i+j];
                row_col_dia[i+45][j]=board[i+j][j];
                row_col_dia[i+60][j]=board[j][14-i-j];
                row_col_dia[i+75][j]=board[i+j][14-j];
            }

        }
    }
/*
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            row_col_dia[i+30][j]=board[j][i+j];
            row_col_dia[i+40][j]=board[i+j][j];
        }
    }

    for(int i=4;i<15;i++)
    {
        for(int j=4;j<15;j++)
        {
            row_col_dia[i+50][j]=board[j][4+i-j];
            row_col_dia[i+60][j]=board[4+i-j][j];
        }
    }*/
    for(int i=0;i<90;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(row_col_dia[i][j]==1&&start==false)
            {
                start=true;
                count++;
                if(row_col_dia[i][j-1]==0)before=false;
                else if(row_col_dia[i][j-1]==-1)before=true;
            }
            else if(row_col_dia[i][j]==1&&start==true)
            {
                count++;

            }
            else if(row_col_dia[i][j]==0&&start==true)
            {
                start=false;
                if(count==1)
                {
                    if(before==false){tempvalue=1;}
                    else{tempvalue=0;}
                    if(row_col_dia[i][j+1]==1&&row_col_dia[i][j+2]==1&&row_col_dia[i][j+3]==1)
                    {
                        tempvalue=15;
                    }

                }
                else if(count==2)
                {
                    if(before==true){tempvalue=2;}
                    else{tempvalue=3;}
                    if(row_col_dia[i][j+1]==1&&row_col_dia[i][j+2]==1)
                    {
                        tempvalue=15;
                    }

                }
                else if(count==3)
                {
                    if(before==false)
                    {
                        tempvalue=8;
                    }
                    else{tempvalue=4;}
                    if(row_col_dia[i][j+1]==1)
                    {
                        tempvalue=15;
                    }
                }
                else if(count==4&&before==true){tempvalue=10;}
                else if(count==4&&before==false){tempvalue=15;}
                else if(count==5){tempvalue=100;}
                if(tempvalue>maxvalue)
                {
                    maxvalue=tempvalue;
                    tempvalue=0;
                }
                count=0;
            }
            else if(row_col_dia[i][j]==-1&&start==true)
            {
                start=false;
                if(before==false)
                {
                    if(count==1)tempvalue=0;
                    else if(count==2)tempvalue=2;
                    else if(count==3)tempvalue=4;
                    else if(count==4)tempvalue=9;

                }
                if(count==5)
                {
                    tempvalue=100;
                }
                if(tempvalue>maxvalue)
                {
                    maxvalue=tempvalue;
                    tempvalue=0;
                }
                count=0;
            }

        }
    }
    return maxvalue;
}

int ctlboard::get_reverse_value(int (*board)[20])               //计算电脑的盘面价值
{
    int maxvalue=0;
    int tempvalue=0;
    int count=0;
    bool start=false;
    bool before=false;
    int row_col_dia[90][20]={{0}};
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            row_col_dia[i][j]=board[i][j];
            row_col_dia[i+15][j]=board[j][i];
            if(i+j<15)
            {
                row_col_dia[i+30][j]=board[j][i+j];
                row_col_dia[i+45][j]=board[i+j][j];
                row_col_dia[i+60][j]=board[j][14-i-j];
                row_col_dia[i+75][j]=board[i+j][14-j];
            }

        }
    }
/*
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            row_col_dia[i+30][j]=board[j][i+j];
            row_col_dia[i+40][j]=board[i+j][j];
        }
    }

    for(int i=4;i<15;i++)
    {
        for(int j=4;j<15;j++)
        {
            row_col_dia[i+50][j]=board[j][4+i-j];
            row_col_dia[i+60][j]=board[4+i-j][j];
        }
    }*/
    for(int i=0;i<90;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(row_col_dia[i][j]==-1&&start==false)
            {
                start=true;
                count++;
                if(row_col_dia[i][j-1]==0)before=false;
                else if(row_col_dia[i][j-1]==1)before=true;
            }
            else if(row_col_dia[i][j]==-1&&start==true)
            {
                count++;

            }
            else if(row_col_dia[i][j]==0&&start==true)
            {
                start=false;
                if(count==1)
                {
                    if(before==false){tempvalue=1;}
                    else{tempvalue=0;}
                    if(row_col_dia[i][j+1]==-1&&row_col_dia[i][j+2]==-1&&row_col_dia[i][j+3]==-1)
                    {
                        tempvalue=15;
                    }

                }
                else if(count==2)
                {
                    if(before==true){tempvalue=2;}
                    else{tempvalue=3;}
                    if(row_col_dia[i][j+1]==-1&&row_col_dia[i][j+2]==-1)
                    {
                        tempvalue=15;
                    }

                }
                else if(count==3)
                {
                    if(before==false)
                    {
                        tempvalue=8;
                    }
                    else{tempvalue=4;}
                    if(row_col_dia[i][j+1]==1)
                    {
                        tempvalue=15;
                    }
                }
                else if(count==4&&before==true){tempvalue=9;}
                else if(count==4&&before==false){tempvalue=15;}
                else if(count==5){tempvalue=100;}
                if(tempvalue>maxvalue)
                {
                    maxvalue=tempvalue;
                    tempvalue=0;
                }
                count=0;
            }
            else if(row_col_dia[i][j]==1&&start==true)
            {
                start=false;
                if(before==false)
                {
                    if(count==1)tempvalue=0;
                    else if(count==2)tempvalue=2;
                    else if(count==3)tempvalue=4;
                    else if(count==4)tempvalue=9;
                }
                if(count==5)
                {
                    tempvalue=100;
                }
                if(tempvalue>maxvalue)
                {
                    maxvalue=tempvalue;
                    tempvalue=0;
                }
                count=0;
            }

        }
    }
    return maxvalue;
}

void ctlboard::result(int flag, int (*board)[20])               //由flag获取二维数组中位置
{
    board[flag/15][flag%15]=-1;
}

void ctlboard::react(int (*board)[20],int player)               //AI
{
    int chess;
    int max=-INF;

    for(int i=1;i<15;i++)
    {
        for(int j=1;j<15;j++)
        {
            if(board[i][j]==0)
            {
                if(board[i-1][j]==1||board[i-1][j]==-1
                        ||board[i+1][j]==1||board[i+1][j]==-1
                        ||board[i][j-1]==1||board[i][j-1]==-1
                        ||board[i][j+1]==1||board[i][j+1]==-1
                        ||board[i-1][j-1]==1||board[i-1][j-1]==-1
                        ||board[i-1][j+1]==1||board[i-1][j+1]==-1
                        ||board[i+1][j+1]==1||board[i+1][j+1]==-1
                        ||board[i+1][j-1]==1||board[i+1][j-1]==-1)
                {
                    board[i][j]=-1;
                    int temp=Min_Value(board);
                    if(max<temp)
                    {
                        max=temp;
                        chess=i*15+j;
                    }
                    board[i][j]=0;
                }



            }
        }
    }
    board[chess/15][chess%15]=-1;
    switchplayer(player);
}

int ctlboard::Min_Value(int (*board)[20])
{
    int min=INF;
    for(int i=1;i<15;i++)
    {
        for(int j=1;j<15;j++)
        {
            if(board[i][j]==0)
            {
                if(board[i-1][j]==1||board[i-1][j]==-1
                        ||board[i+1][j]==1||board[i+1][j]==-1
                        ||board[i][j-1]==1||board[i][j-1]==-1
                        ||board[i][j+1]==1||board[i][j+1]==-1
                        ||board[i-1][j-1]==1||board[i-1][j-1]==-1
                        ||board[i-1][j+1]==1||board[i-1][j+1]==-1
                        ||board[i+1][j+1]==1||board[i+1][j+1]==-1
                        ||board[i+1][j-1]==1||board[i+1][j-1]==-1)
                {
                    board[i][j]=1;
                    int temp=get_reverse_value(board)-get_value(board);
                    if(min>temp)
                    {
                        min=temp;
                    }
                    board[i][j]=0;
                }
            }

        }
    }
    return min;
}

int ctlboard::Max_Value(int (*board)[20])
{
    int max=INF;
    for(int i=1;i<15;i++)
    {
        for(int j=1;j<15;j++)
        {
            if(board[i][j]==0)
            {
                if(board[i-1][j]==1||board[i-1][j]==-1
                        ||board[i+1][j]==1||board[i+1][j]==-1
                        ||board[i][j-1]==1||board[i][j-1]==-1
                        ||board[i][j+1]==1||board[i][j+1]==-1
                        ||board[i-1][j-1]==1||board[i-1][j-1]==-1
                        ||board[i-1][j+1]==1||board[i-1][j+1]==-1
                        ||board[i+1][j+1]==1||board[i+1][j+1]==-1
                        ||board[i+1][j-1]==1||board[i+1][j-1]==-1)
                {
                    board[i][j]=-1;
                    int temp=get_reverse_value(board)-get_value(board);
                    if(temp>max)
                    {
                        max=temp;
                    }
                    board[i][j]=0;
                }
            }

        }
    }
    return max;
}
