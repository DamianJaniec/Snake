#include <vector>

class Board
{
	int height, width;
	std::vector<std::vector<int>> board;
public:
	void makeBoard();
	void setSize(int x, int y);
};