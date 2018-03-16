#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
using namespace std;

#ifndef _console_header
#define _console_header

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7


#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077
#define key_none	-1

//--------------------------------------------------------

#include <windows.h>

//--------------------------------------------------------

int inputKey();

//-------------------------Screen-------------------------
void clrscr();

//screen: goto [x,y]
void gotoXY (int column, int line);

//screen: get [x]
int whereX();

//screen: get [y]
int whereY();

void TextColor (int color);
//end----------------------Screen----------------------end

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

#endif
#define consoleWidth 60
#define consoleHeight 32
enum TrangThai { UP,DOWN,LEFT,RIGHT };

struct ToaDo
{
    int x,y; // y la tung do, x la hoanh do
};

struct Snake
{
    ToaDo dot[31];
    int n;
    TrangThai tt;
    int diem;
};

struct HoaQua
{
    ToaDo td;
};

void Khoitao(Snake &snake, HoaQua &hq)
{
    snake.n=3;
    snake.diem=0;
    snake.dot[0].x=3;
    snake.dot[0].y=0;
    snake.dot[1].x=2;
    snake.dot[1].y=0;
    snake.dot[2].x=1;
    snake.dot[2].x=0;
    snake.tt=RIGHT;
    hq.td.x=10;
    hq.td.y=10;
}

void HienThi(Snake snake, HoaQua hq)
{
    clrscr();
    TextColor (8+rand()%8);
    for(int i=0;i<consoleHeight;i++)
    {
        gotoXY(consoleWidth,i);
        cout << "|";
    }
    TextColor (8+rand()%8);
    gotoXY(hq.td.x,hq.td.y);
    cout << "+";
    TextColor (9);
    gotoXY(snake.dot[0].x,snake.dot[0].y);
        cout << char(3);
    for(int i=1;i<snake.n;i++)
    {
        gotoXY(snake.dot[i].x,snake.dot[i].y);
        cout << "*";
    }
    TextColor(10);
	//hien thi trang thai game
	gotoXY(consoleWidth+2,1);
	cout << "Diem = " << snake.diem;
}

void DieuKhien_DiChuyen(Snake &snake)
{
    //truyen trang thai dot cu
    for(int i=snake.n-1;i>0;i--)
        snake.dot[i]=snake.dot[i-1];

    if(kbhit())
    {
        int key=_getch();

        //dieu khien  cai dau
        if(key=='A'||key=='a')
            snake.tt=LEFT;
        else if(key=='D'||key=='d')
            snake.tt=RIGHT;
        else if(key=='W'||key=='w')
            snake.tt=UP;
        else if(key=='S'||key=='s')
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
// tra ve 0 neu 0 co gi
// tra ve -1 neu game ket thuc
int XuLy(Snake &snake, HoaQua &hq,int &ThoiGianSleep)
{
    if(snake.dot[0].x<0||snake.dot[0].x>=consoleWidth||
       snake.dot[0].y<0||snake.dot[0].y>=consoleHeight-1)
        return -1;
    for(int i=1;i<snake.n;i++)
        if(snake.dot[0].x==snake.dot[i].x&&
           snake.dot[0].y==snake.dot[i].y)
           return -1;
    if(snake.dot[0].x==hq.td.x&&snake.dot[0].y==hq.td.y)
    {
        // an duoc hoa qua
        for(int i=snake.n;i>0;i--)
            snake.dot[i]=snake.dot[i-1];
        snake.n++;
        snake.diem++;
        if(snake.tt==UP)
            snake.dot[0].y--;
        else if(snake.tt==DOWN)
            snake.dot[0].y++;
        else if(snake.tt==RIGHT)
            snake.dot[0].x++;
        else if(snake.tt==LEFT)
            snake.dot[0].x--;
        hq.td.x=rand()%consoleWidth;
        hq.td.y=rand()%consoleHeight;
        if(ThoiGianSleep>30)
        {
            ThoiGianSleep-=20;
        }
    }

}

int main()
{
    srand(time(NULL)); // khoi tao bo sinh so ngau nhien
    Snake snake;
    HoaQua hq;
    Khoitao(snake,hq);
    int ma=0;
    int ThoiGianSleep=400;
    while(1)
    {
        //hien thi
        HienThi(snake,hq);

        // dieu khien
        DieuKhien_DiChuyen(snake);
         // xu li
         // gameover
        ma= XuLy(snake, hq,ThoiGianSleep);
        if(ma==-1) //thua cuoc
        {
            gotoXY((consoleWidth-3)/2,(consoleHeight-2)/2);
            TextColor(5);
            cout << char(157)<< "  "<<"GAMEOVER"<<"  "<<char(157);
            while(_getch()!=13);
            break;
        }
         Sleep(ThoiGianSleep);
    }

    return 0;
}
