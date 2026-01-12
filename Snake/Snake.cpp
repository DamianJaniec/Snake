#include "Snake.h"

int Snake::addNode()
{
	Point tmp;
	nodes.push_back(tmp);

	return nodes.size();
}
void Snake::setNodePos(int a, int _x, int _y)
{
	nodes[a].setPos(_x, _y);
}
void Snake::setNodePosRand(int a)
{
	nodes[a].setRandomPos();
}
void Snake::setNodeChar(int a, char _c)
{
	nodes[a].setChar(_c);
}
void Snake::setDirr(int _dirr)
{
	dirr = _dirr;
}
void Snake::move(Board &b)
{
	
	b.setChar(nodes[nodes.size() - 1].getPos()[0], nodes[nodes.size() - 1].getPos()[1], '.');
	
	
	for (int i = nodes.size(); i > 1; i++)
	{
		nodes[i].setPos(nodes[i - 1].getPos()[0],nodes[i-1].getPos()[1]);
	}
	nodes[0].moveNode(dirr);

	for(int i=0; i<nodes.size(); i++)
		b.setChar(nodes[i].getPos()[0], nodes[i].getPos()[1], nodes[i].getChar());
}