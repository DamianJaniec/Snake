#include <time.h>
#include <cstdlib>
#include <vector>

#include "Point.h"
#include "def.h"

void Point::setPos(int _x, int _y)
{
	x = _x;
	y = _y;
}
std::vector<int> Point::getPos()
{
	return std::vector<int> {x, y};
}
void Point::setRandomPos()
{
	srand(time(NULL));

	x = rand()% (WIDTH - 2) + 1; //1...WIDTH-1
	y = rand()% (HEIGHT - 2) + 1; // 1...HEIGHT-1;
}
void Point::setChar(char _c)
{
	c = _c;
}
char Point::getChar()
{
	return c;
}
void Point::moveNode(int a)
{
	switch (a)
	{
	case 2:
		y--;
		break;
	case 4:
		x--;
		break;
	case 6:
		x++;
		break;
	case 8:
		y++;
		break;
	}
}