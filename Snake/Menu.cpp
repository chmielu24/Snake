#include "Menu.h"
#include "SnakeGame.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>

Menu::Menu()
{
	selected = 0;
	std::cin.clear();
	GetAsyncKeyState(13);
}


Menu::~Menu()
{
}

void Menu::Update()
{
	//Jeœli nast¹pi³o naciœniêcie klawisza enter
	if(GetAsyncKeyState(13)) //ENTER
	{
		switch (selected)
		{
		case 0: Game::Instance().LoadScene(new SnakeGame()); break; //Wczytujemy Gre
		case 1: Game::Instance().Exit(); break; //Koñczymy dzia³anie aplikacji
		default:
			break;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN)) //Jeœli nast¹pi³o naciœniêcie strza³ki w dó³ 
	{
		selected = 1;
		DrawArrow(1, "-->"); // na y=1 pozycji rysujemy strza³ke
		DrawArrow(0, "   "); // marzemy strza³kê z pozycji y=0

	}
	else if (GetAsyncKeyState(VK_UP))
	{
		selected = 0;
		DrawArrow(0, "-->");// na y=0 pozycji rysujemy strza³ke
		DrawArrow(1, "   "); // marzemy strza³kê z pozycji y=1

	}
}

//rysujemy menu przy wczytaniu sceny
void Menu::Draw()
{
	cout << "--> Start Game\n" << "    Exit\n\n"
		<<"Use UP/Down Arrow\n";
}

//rysuje ci¹g znaków s przy wybranej opcji
void Menu::DrawArrow(int pos, string s)
{
	//przesuwamy kursor do danej pozycji 
	COORD c;
	c.X = 0;
	c.Y = pos; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	//wypisujemy tekst na tej pozycji
	cout << s;

	//Ustawiamy kursor spowrotem na pozycje 0,0 ¿eby nie miga³ na œrodku 
	c.X = 0;
	c.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}