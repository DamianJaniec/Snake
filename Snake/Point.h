#include <vector>

//one node of snake

class Point
{
	int x, y;

public: 
	void setPos(int x, int y);
	std::vector<int> getPos();
};