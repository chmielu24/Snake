#include "Food.h"
#include <random>
#include <time.h>

Food::Food()
{
	srand(time(NULL));

}

void Food::GenerateFood(Board * board)
{
	bool is_good = false;

	int x1, y1;
	while (!is_good)
	{
		x1 = rand() % (board->GetSize() - 2) + 1;
		y1 = rand() % (board->GetSize() - 2) + 1;

		if (board->GetType(x1, y1) == Types::Empty)
			is_good = true;
	}

	x = x1;
	y = y1;

	board->SetType(x1, y1, Types::Food);
	board->DrawFood();
}
