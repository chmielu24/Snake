#pragma once
#include <vector>
#include "Character.h"

using namespace std;

class Snake
{
public:
	Snake();
	virtual ~Snake();
	void Draw();

	//Dodaje cia�o na pozycji x,y
	void AddBody(int x, int y);

	//Dodaje cia�o na ogonie
	void AddBody();

	//przesuwa w�a
	void Move(int x, int y);

	//Zwraca g�ow w�a
	Character &GetFirst() { return *body[0]; }

	//Sprawdza czy g�owa w�a nie kolidiuje z reszt� jesgo cia�a
	bool Collision();


protected:
	//Kontener zawieraj�cy wszystkie kawa�ki cia�a
	std::vector<Character*> body;

	//W jakim kierunku aktualnie przesuwa si� nasz w�� 
	int xVector;
	int yVector;
};

