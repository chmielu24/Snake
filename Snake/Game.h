#pragma once
#include "iScene.h"

//G��wna klasa zarz�dzaj�ca gr�
class Game
{

public:
	//W tej funkcji znajduje si� g��wna p�tla gry
	void Start();

	//koniec gry
	void Exit();

	//Funkcja tworzy statyczny obiekt Game oraz zwracago przez co mo�e w instnie� tylko 1 obiekt klasy Game
	static Game& Instance()
	{
		static Game game;
		return game;
	}

	//Wczytuje scene Menu lub SnakeGame
	void LoadScene(iScene *newScene);

	//Wirtualny destruktor aby mo�na by�o dziedziczy� po tej klasie
	virtual ~Game();

protected:
	Game();

	//Aktualna Scena kt�ra jest wczytana
	iScene *AccualScene;

	//Czy aplikacja jest w��czona, false ko�czy dzia�anie programu
	bool isOpen;

};