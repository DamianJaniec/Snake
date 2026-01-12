// Snake.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h> // _kbhit, _getch

#include "Snake.h"
#include "Board.h"
#include "gui.h"

#include "def.h"

Snake snake;
Board board;
Display dis;


void init();
void game();

int main()
{
	init();
	game();

}


void init()
{
	cursor(false);
	
	
	board.setSize(WIDTH, HEIGHT);
	board.makeBoard();
	dis.displayBoard(board);

	snake.addNode();
	snake.setNodePosRand(0); //seting head pos
	snake.setNodeChar(0, 'X'); //setting head char
	
}

void game()
{
	char key;

	while (true)
	{
		if (_kbhit()) {
			key = _getch();

			if (key == 'w') snake.setDirr(2);
			if (key == 's') snake.setDirr(8);
			if (key == 'a') snake.setDirr(4);
			if (key == 'd') snake.setDirr(6);
			if (key == 'x') break;
		}

		snake.move(board);


		dis.displayChgBoard(board);
		board.updateBoard();

		Sleep(1000); //for now, bcs im sleepy and dont see a.... nothing
	}
}
