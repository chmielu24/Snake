#pragma once
#include "Character.h"

class Board
{
public:
	Board(int size);
	virtual ~Board();

	//zwraca typ planszy na pozycji x,y
	Types GetType(int x, int y) { return board[x][y].GetType(); }

	//Ustawia typ planszy na pozycji x,y
	void SetType(int x, int y, Types t) { board[x][y].SetType(t); }

	//Rysuje ca³¹ plansze
	void Draw();

	//Rysuje wybrany punkt planszy
	void Draw(int x, int y);

	//Rysuje jedzenie na planszy
	void DrawFood();

	//Zwraca rozmiar planszy
	const int GetSize() { return Size; }

protected:
	//nasza plansza sk³adaj¹ca siê z pojedynczych bloków
	Character **board;

	//Rozmiar Planszy x,y
	int Size;
};

