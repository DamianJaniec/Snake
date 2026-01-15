#pragma once

#include <windows.h>
#include <wchar.h>
#include "Board.h"


void color(int k);
void cursor(bool tf);
void gotoxy(int x, int y);
void initFont();

class Display
{
public:
	void displayBoard(Board& b); //display firts time
	void displayChgBoard(Board& b); //display when something slighty changes (minimalizing "Refresh effects")
	void displayColorChar(char c);
};
