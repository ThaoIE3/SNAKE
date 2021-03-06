#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#define consoleWidth 40
#define consoleHeight 20
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
#define     KEY_LEFT    VK_LEFT
#define     KEY_RIGHT   VK_RIGHT
#define     KEY_UP      VK_UP
#define     KEY_DOWN    VK_DOWN
#include <windows.h>

void gotoXY (int column, int line);

void TextColor (int color);

bool checkKey(int key);

void clrscr();

void Nocursortype();
#endif // CONSOLE_H_INCLUDED
