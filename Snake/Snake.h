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

	//Dodaje cia³o na pozycji x,y
	void AddBody(int x, int y);

	//Dodaje cia³o na ogonie
	void AddBody();

	//przesuwa wê¿a
	void Move(int x, int y);

	//Zwraca g³ow wê¿a
	Character &GetFirst() { return *body[0]; }

	//Sprawdza czy g³owa wê¿a nie kolidiuje z reszt¹ jesgo cia³a
	bool Collision();


protected:
	//Kontener zawieraj¹cy wszystkie kawa³ki cia³a
	std::vector<Character*> body;

	//W jakim kierunku aktualnie przesuwa siê nasz w¹¿ 
	int xVector;
	int yVector;
};

