#include "Character.h"
#include <Windows.h>
#include <iostream>

Character::Character()
{

}


Character::~Character()
{

}

void Character::Draw()
{
	COORD c;

	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	putchar((char)type);

	c.X = 0;
	c.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}
