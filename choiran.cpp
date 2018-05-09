#include"choiran.h"

void choiran(Snake &snake, HoaQua &hq)
{
    Khoitao(snake,hq);
    int ma=0;
    int ThoiGianSleep=300;
    while(1)
    {
        HienThi(snake,hq);
        DieuKhien_DiChuyen(snake);
        ma= XuLy(snake, hq,ThoiGianSleep);
        if(ma==-1)
        {
            gotoXY((consoleWidth-5)/2,(consoleHeight-2)/2);
            TextColor(ColorCode_Yellow);
            cout << char(157)<< "  "<<"GAMEOVER"<<"  "<<char(157) << endl;
            while(_getch()!=13);
            break;
        }
         Sleep(ThoiGianSleep);
    }
}
