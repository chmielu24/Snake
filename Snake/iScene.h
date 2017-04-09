#pragma once


//Interfejs po którym dziedzicz¹ klasy Menu oraz SnakeGame
//dziêki temu w klasie Game mo¿na przypisaæ iScene = new Menu(); lub iScene = new SnakeGame();
class iScene
{
public:

	/*funckje virtualne nale¿y je napisaæ w klasach pochodnych */

	//Funkcja która wykonuje siê co klatke
	virtual void Update() = 0;

	//Funkcja która rysuje scene na starcie
	virtual void Draw() = 0;

	virtual ~iScene() {};
};