#pragma once
#include <vector>
#include "Point.h"
#include "Board.h"

class Snake
{
	std::vector<Point> nodes;
	int dirr = 0;

public:
	int addNode();
	void setNodePos(int a,int _x, int _y);
	void setNodePosRand(int a);
	void setNodeChar(int a, char _c);
	void setDirr(int _dirr);
	void move(Board &b);
};