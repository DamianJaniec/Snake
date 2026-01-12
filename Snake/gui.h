#pragma once

#include <windows.h>
#include "Board.h"


void color(int k);
void cursor(bool tf);
void gotoxy(int x, int y);

class Display
{
public:
	void displayBoard(Board& b); //display firts time
	void displayChgBoard(Board& b); //display when something slighty changes (minimalizing "Refresh effects")
};
