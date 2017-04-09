#pragma once
#include "Types.h"


//odpowiada za pojedynczy bloczek
class Character
{
public:
	Character();
	virtual ~Character();

	//Zwraca X
	int &GetX() { return x; }

	//Zwraca Y
	int &GetY() { return y; }

	//Zwraca jakiego typu jest ten bloczek
	const Types GetType() { return type; }

	//Ustawia typ
	void SetType(Types t) { type = t; }

	//Rysuje nasz bloczek na pozycji x,y
	void Draw();

protected:
	int x, y;
	Types type;
};

