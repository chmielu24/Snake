#pragma once
#include "iScene.h"
#include "Board.h"
#include "Snake.h"
#include "Food.h"

//Klasa SnakeGame dziedziczy po iScene
class SnakeGame :
	public iScene
{
public:
	SnakeGame();
	virtual ~SnakeGame();

	// Funkcje z interfejsu iScene
	virtual void Update() override;
	virtual void Draw() override;


protected:
	//Plansza
	Board board;

	//nasz snake
	Snake snake;

	Food food[3];

	//iloœæ punktów +1 po zjedzenu jedzenia
	int Score;


	//Przegrana
	void SetGameOver();
	bool GameOver;
};
 
