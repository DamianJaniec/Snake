#pragma once
#include <vector>


class Board
{
	int height, width;
protected:
	std::vector<std::vector<char>> board;
	std::vector<std::vector<char>> oldBoard;
public:
	void makeBoard();
	void setSize(int x, int y);
	void setChar(int x, int y, char c);
	char getOldChar(int x, int y);
	char getChar(int x, int y);
	void updateBoard();

	friend class Display;
	friend class Snake;
};