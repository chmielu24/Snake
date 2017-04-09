#pragma once
#include "iScene.h"
#include <string>
using namespace std;

//Klasa Menu dziedziczy po iScene
class Menu :
	public iScene
{
public:
	Menu();
	virtual ~Menu();

	// Funkcje z interfejsu iScene
	virtual void Update() override;
	virtual void Draw() override;

protected:

	//rysuje ci�g znak�w s przy wybranej opcji
	void DrawArrow(int pos, string s);

	//kt�ra opcja jest wybrana w menu, Start game czy exit
	int selected; 
};

