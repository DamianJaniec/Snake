#pragma once
//one node of snake

class Point
{
	int x, y;
	char c;

public: 
	void setPos(int _x, int _y);
	std::vector<int> getPos();
	void setRandomPos();
	void setChar(char _c);
	char getChar();
	void moveNode(int a);
};