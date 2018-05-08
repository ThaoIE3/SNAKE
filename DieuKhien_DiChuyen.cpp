#include"DieuKhien_DiChuyen.h"

void DieuKhien_DiChuyen(Snake &snake)
{
    for(int i=snake.n-1;i>0;i--)
        snake.dot[i]=snake.dot[i-1];

    if(checkKey(KEY_LEFT))
        {
            if(snake.tt!=RIGHT)
            snake.tt=LEFT;
        }

    else if(checkKey(KEY_RIGHT))
         {
             if(snake.tt!=LEFT)
             snake.tt=RIGHT;
         }
    else if(checkKey(KEY_UP))
        {
            if(snake.tt!=DOWN)
            snake.tt=UP;
        }
    else if(checkKey(KEY_DOWN))
        {
            if(snake.tt!=UP)
             snake.tt=DOWN;
        }

    if(snake.tt==UP)
        snake.dot[0].y--;

    else if(snake.tt==DOWN)
        snake.dot[0].y++;

    else if(snake.tt==RIGHT)
        snake.dot[0].x++;

    else if(snake.tt==LEFT)
        snake.dot[0].x--;
}
