#include"HienThi.h"
#include"console.h"
#include"struct.h"

using namespace std;

moto buffer[consoleHeight][consoleWidth+1];

void vemoto(int dong,int cot,int kitu,int mau)
{
    buffer[dong][cot].kitu=kitu;
    buffer[dong][cot].mau=mau;
}

void HienThi(Snake snake, HoaQua hq)
{
    //ve 4 bien
    for(int i=0;i<=consoleHeight;i++)
        vemoto(i,consoleWidth,186,ColorCode_DarkPink);
    for(int i=0;i<=consoleWidth;i++)
        vemoto(consoleHeight-1,i,205,ColorCode_DarkPink);
    for(int i=0;i<=consoleWidth;i++)
        vemoto(0,i,205,ColorCode_DarkPink);
    for(int i=0;i<consoleHeight;i++)
        vemoto(i,0,186,ColorCode_DarkPink);

    vemoto(0,0,201,ColorCode_DarkPink);
    vemoto(consoleHeight-1,0,200,ColorCode_DarkPink);
    vemoto(0,consoleWidth,187,ColorCode_DarkPink);
    vemoto(consoleHeight-1,consoleWidth,188,ColorCode_DarkPink);


    vemoto(hq.td.y,hq.td.x,'+',ColorCode_Red);//ve hoa qua
    vemoto(hq.td.y+1,hq.td.x,'+',ColorCode_Red);
    vemoto(hq.td.y,hq.td.x+1,'+',ColorCode_Red);
    vemoto(hq.td.y+1,hq.td.x+1,'+',ColorCode_Red);


    vemoto(snake.dot[0].y,snake.dot[0].x,'@',ColorCode_Cyan); // ve dau ran

    for(int i=1;i<snake.n;i++)
        vemoto(snake.dot[i].y,snake.dot[i].x,'*',ColorCode_Cyan);//ve than ran
    gotoXY(0,0);
    for(int i=0;i<consoleHeight;i++)
    {
        for(int j=0;j<=consoleWidth;j++)
        {
            TextColor(buffer[i][j].mau);
            cout << buffer[i][j].kitu;
            buffer[i][j].kitu=' ';
        }
        if(i<consoleHeight-1)
            cout << "\n";
    }
    TextColor(ColorCode_Green);
	gotoXY(consoleWidth+2,1);
	cout << "Diem = " << snake.diem*10;//hien thi diem

	gotoXY(consoleWidth+2,3);
	cout << "So hoa qua ran an duoc: " << snake.n-3;
}
