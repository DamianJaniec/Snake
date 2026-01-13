#include "Snake.h"
#include "def.h"

void Snake::addNode()
{
	Point tmp;
	this->nodes.push_back(tmp);
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
	switch (_dirr)
	{
	case 2:
		if (dirr != 8)
			dirr = _dirr;
		break;
	case 8:
		if (dirr != 2)
			dirr = _dirr;
		break;
	case 4:
		if (dirr != 6)
			dirr = _dirr;
		break;
	case 6:
		if (dirr != 4)
			dirr = _dirr;
		break;
	}
	
}
int Snake::move(Board &b)
{
	int col = 0;
	
	if (!grow) {
		b.setChar(nodes[nodes.size() - 1].getPos()[0],
			nodes[nodes.size() - 1].getPos()[1], '.');
	}
	

	for (int i = nodes.size()-1; i > 0; i--)
		nodes[i].setPos(nodes[i - 1].getPos()[0],nodes[i-1].getPos()[1]);
	nodes[0].moveNode(dirr);

	if (dirr != 0) //if movin' somewhere
	{
		char c = b.getOldChar(nodes[0].getPos()[0], nodes[0].getPos()[1]);
		if (c != '.') // basic colision
		{
			if (c == FOOD_CHAR)
			{
				addTail();
				grow = false;
				col = 1;
			}
			else
				col = 2;
		}
	}
	

	for(int i=0; i<nodes.size(); i++)
		b.setChar(nodes[i].getPos()[0], nodes[i].getPos()[1], nodes[i].getChar());

	return col; //no colision
}
int Snake::addTail()
{
	grow = true; 

	Point tmp;
	nodes.push_back(tmp);

	int newIdx = nodes.size() - 1;
	int prevIdx = newIdx - 1;

	nodes[newIdx].setPos(nodes[prevIdx].getPos()[0],
		nodes[prevIdx].getPos()[1]);
	nodes[newIdx].setChar(NODE_CHAR);

	return nodes.size();
}