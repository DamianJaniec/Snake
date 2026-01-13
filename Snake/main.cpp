// Snake.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h> // _kbhit, _getch
#include <time.h>
#include <cstdlib>


#include "Snake.h"
#include "Board.h"
#include "gui.h"
#include "Point.h"

#include "def.h"

Snake snake;
Board board;
Display dis;
Point fruit;


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
	srand(time(NULL));
	
	board.setSize(WIDTH, HEIGHT);
	board.makeBoard();
	dis.displayBoard(board);

	snake.addNode();
	snake.setNodePosRand(0); //seting head pos
	snake.setNodeChar(0, HEAD_CHAR); //setting head char

	fruit.setChar(FOOD_CHAR);
	fruit.setRandomFreePos(board);

	dis.displayChgBoard(board);
	board.updateBoard();
	
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
		int collision = snake.move(board);
		if ( collision == 1)
		{
			
			fruit.setRandomFreePos(board);
		}
		else if (collision == 2 || collision == 3)
		{
			printf("Collision");
			break;
		}


		dis.displayChgBoard(board);
		board.updateBoard();

		Sleep(200); //for now, bcs im sleepy and dont see a.... nothing
	}
}
