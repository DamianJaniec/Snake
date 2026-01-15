#include "gui.h"
#include "Board.h"
#include "def.h"

void color(int k)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}
void cursor(bool tf)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = tf;
    SetConsoleCursorInfo(console, &cursorInfo);
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Display::displayBoard(Board &b)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            gotoxy(j, i);
            //printf("%c", b.getChar(j, i));
            displayColorChar(b.getChar(j, i));
        }
    }
}
void Display::displayChgBoard(Board& b)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (b.getChar(j, i) != b.getOldChar(j, i))
            {
                gotoxy(j, i);
                displayColorChar(b.getChar(j, i));
                //printf("%c", b.getChar(j, i));
            }
            
        }
    }
}
void Display::displayColorChar(char c)
{
    switch (c)
    {
    case 'X': color(HEAD_COLR); break;
    case 'Z': color(FOOD_COLR); break;
    case 'O': color(NODE_COLR); break;
    case '#': color(WALL_COLR); break;
    case '.': color(BLNK_COLR); break;
    default: color(DFLT_COLR);  break;
    }
    
    printf("%c", c);
}
void initFont()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

    cfi.dwFontSize.X = 16;
    cfi.dwFontSize.Y = 16;
    cfi.FontWeight = FW_NORMAL;
    cfi.FontFamily = FF_MODERN;
    wcscpy_s(cfi.FaceName, L"Terminal");

    SetCurrentConsoleFontEx(hConsole, TRUE, &cfi);
}