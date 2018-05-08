#include"Khoitao.h"

void Khoitao(Snake &snake, HoaQua &hq)
{
    snake.n=3;
    snake.diem=0;
    snake.dot[0].x=3;
    snake.dot[0].y=5;
    snake.dot[1].x=2;
    snake.dot[1].y=5;
    snake.dot[2].x=1;
    snake.dot[2].x=5;
    snake.tt=RIGHT;
    snake.dot[0].x++;
    hq.td.x=10;
    hq.td.y=10;

}
