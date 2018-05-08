#include"XuLy.h"

int XuLy(Snake &snake, HoaQua &hq,int &ThoiGianSleep)
{
    if(snake.dot[0].x<1||snake.dot[0].x>=consoleWidth||
       snake.dot[0].y<1||snake.dot[0].y>=consoleHeight-1)
        return -1;
    for(int i=2;i<snake.n;i++)
        if(snake.dot[0].x==snake.dot[i].x&&
           snake.dot[0].y==snake.dot[i].y)
           return -1;
    if(snake.dot[0].x==hq.td.x&&snake.dot[0].y==hq.td.y)
    {
        for(int i=snake.n;i>0;i--)
            snake.dot[i]=snake.dot[i-1];
        snake.n++;
        snake.diem++;
        if(snake.diem%5==0)
            snake.diem=snake.diem*1.5;
        if(snake.tt==UP)
            snake.dot[0].y--;
        else if(snake.tt==DOWN)
            snake.dot[0].y++;
        else if(snake.tt==RIGHT)
            snake.dot[0].x++;
        else if(snake.tt==LEFT)
            snake.dot[0].x--;
        hq.td.x=1+rand()%(consoleWidth-1);
        hq.td.y=1+rand()%(consoleHeight-2);
        if(ThoiGianSleep>30)
            ThoiGianSleep-=20;
    }
}

