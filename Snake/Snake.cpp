#include "Snake.h"
#include <Windows.h>


Snake::Snake()
{
	//uwtawiamy �e na starcie w�� porusza si� w prawo
	xVector = 1;
	yVector = 0;

	//Dodajemy mu 4 bloki cia�a
	AddBody(10, 10);
	AddBody(9, 10);
	AddBody(8, 10);
	AddBody(7, 10);

}


Snake::~Snake()
{
	//Sprz�tamy po klasie
	for (int i = 0; i < body.size(); ++i)
		delete body[i];
}

//Dodaje cia�o na pozycji x,y
void Snake::AddBody(int x, int y)
{
	Character* ch = new Character;
	ch->GetX() = x;
	ch->GetY() = y;
	ch->SetType(Types::Snake);

	body.push_back(ch);
}

//Dodaje cia�o na ogonie
void Snake::AddBody()
{
	Character* ch = new Character;
	ch->GetX() = body[body.size()-1]->GetX();
	ch->GetY() = body[body.size()-1]->GetY();
	ch->SetType(Types::Snake);

	body.push_back(ch);

}


void Snake::Move(int x, int y)
{	
	//sprawdzamy czy aktualnie porusza si� w lini poziomej
	if(xVector != 0)
		if (y != 0) //Je�li u�ytkownik chce skr�ci� w g�re lub d�
		{
			xVector = 0;
			yVector = y;
		}

	//sprawdzamy czy aktualnie porusza si� w lini pionowej
	if (yVector != 0)
		if (x != 0) // Je�li u�ytkownik chce skr�ci� w lewo lub prawo
		{ 
			xVector = x;
			yVector = 0;
		}

	COORD c;

	//usuwa ostatni kawa�ek w�a 
	//Je�li doda�o cia�o nie usuwa ostatniego bloku 
	//poniwea� dodanie cia�a dodaje go na tej samej pozycji co ogon
	if (body[body.size() - 1]->GetX() != body[body.size() - 2]->GetX()
		|| body[body.size() - 1]->GetY() != body[body.size() - 2]->GetY())
	{
		c.X = body[body.size() - 1]->GetX();
		c.Y = body[body.size() - 1]->GetY();

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

		putchar((char)Types::Empty);

		body[body.size() - 1]->GetX() = body[body.size() - 2]->GetX();
		body[body.size() - 1]->GetY() = body[body.size() - 2]->GetY();	
	}
	
	//zmienia pozycje wsyztkich element�w na pozycje nast�pnego elementu
	for (int i = body.size() - 2; i > 0; --i)
	{	
		body[i]->GetX() = body[i-1]->GetX();
		body[i]->GetY() = body[i-1]->GetY();
	}

	//przesuwa g�owe o nasz wektor przesuniecia
	body[0]->GetX() += xVector;
	body[0]->GetY() += yVector;

	c.X = body[0]->GetX();
	c.Y = body[0]->GetY();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	//rysuje now� g�owe
	putchar((char)Types::Snake);

	c.X = 0;
	c.Y = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

bool Snake::Collision()
{
	for (int i = 1; i < body.size(); i++)
	{
		//Je�li nast�pi�a kolizja cia�a w�a z g�ow� zwraca true
		if (body[0]->GetX() == body[i]->GetX() && body[0]->GetY() == body[i]->GetY())
		{
			return true;
		}
	}

	return false;
}


void Snake::Draw()
{
	for (int i = 0; i < body.size(); ++i)
		body[i]->Draw();
}