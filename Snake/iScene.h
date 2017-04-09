#pragma once


//Interfejs po kt�rym dziedzicz� klasy Menu oraz SnakeGame
//dzi�ki temu w klasie Game mo�na przypisa� iScene = new Menu(); lub iScene = new SnakeGame();
class iScene
{
public:

	/*funckje virtualne nale�y je napisa� w klasach pochodnych */

	//Funkcja kt�ra wykonuje si� co klatke
	virtual void Update() = 0;

	//Funkcja kt�ra rysuje scene na starcie
	virtual void Draw() = 0;

	virtual ~iScene() {};
};