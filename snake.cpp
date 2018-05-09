#include<time.h>
#include"choiran.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Snake snake;
    HoaQua hq;
    char keychar;
    while(1)
    {
        TextColor(ColorCode_DarkYellow);
        cout << "\n  ===== SNAKE WISE =====\n\n"
                " Cach tinh diem: cu sau 5 qua an duoc thi diem tang gap ruoi\n\n"
                " Chuc ban dat duoc so diem cao nhe !!! \n\n"
                " Hay nhan phim P or p de choi nao... Let go !";

        keychar=_getch();

        if(keychar=='P' || keychar == 'p')
        {
            clrscr();
            choiran(snake,hq);
        }
    }

    return 0;
}

