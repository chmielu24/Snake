#pragma once
#include "Board.h"

class Food
{
public:
	Food();
	virtual ~Food() {}

	void GenerateFood(Board * board);


	const int X() { return x; }
	const int Y() { return y; }

protected:
	int x;
	int y;
};