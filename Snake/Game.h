#pragma once
#include "iScene.h"

//G³ówna klasa zarz¹dzaj¹ca gr¹
class Game
{

public:
	//W tej funkcji znajduje siê g³ówna pêtla gry
	void Start();

	//koniec gry
	void Exit();

	//Funkcja tworzy statyczny obiekt Game oraz zwracago przez co mo¿e w instnieæ tylko 1 obiekt klasy Game
	static Game& Instance()
	{
		static Game game;
		return game;
	}

	//Wczytuje scene Menu lub SnakeGame
	void LoadScene(iScene *newScene);

	//Wirtualny destruktor aby mo¿na by³o dziedziczyæ po tej klasie
	virtual ~Game();

protected:
	Game();

	//Aktualna Scena która jest wczytana
	iScene *AccualScene;

	//Czy aplikacja jest w³¹czona, false koñczy dzia³anie programu
	bool isOpen;

};