#include "Board.h"
#include "def.h"

void Board::makeBoard()
{
	board.resize(height,std::vector<char>(width,'.'));

	//making frame inside box
	for (int i = 0; i < height; i++)
	{
		board[i][0] = WALL_CHAR;
		board[i][width - 1] = WALL_CHAR;
	}
	for (int i = 0; i < width; i++)
	{
		board[0][i] = WALL_CHAR;
		board[height - 1][i] = WALL_CHAR;
	}
	oldBoard = board;
}
void Board::setSize(int x, int y)
{
	height = x;
	width = y;
}
void Board::setChar(int x, int y, char c)
{
	board[x][y] = c;
}
char Board::getChar(int x, int y)
{
	return board[x][y];
}
char Board::getOldChar(int x, int y)
{
	return oldBoard[x][y];
}
void Board::updateBoard()
{
	oldBoard = board;
}