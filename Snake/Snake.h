#pragma once
#include <vector>
#include "Point.h"
#include "Board.h"

class Snake
{
	std::vector<Point> nodes;
	int dirr = 0;
	bool grow = false;

public:
	void addNode();
	void setNodePos(int a,int _x, int _y);
	void setNodePosRand(int a);
	void setNodeChar(int a, char _c);
	void setDirr(int _dirr);
	int move(Board &b);
	int addTail();
};