#include "Snake.h"
#include <Windows.h>


Snake::Snake()
{
	//uwtawiamy ¿e na starcie w¹¿ porusza siê w prawo
	xVector = 1;
	yVector = 0;

	//Dodajemy mu 4 bloki cia³a
	AddBody(10, 10);
	AddBody(9, 10);
	AddBody(8, 10);
	AddBody(7, 10);

}


Snake::~Snake()
{
	//Sprz¹tamy po klasie
	for (int i = 0; i < body.size(); ++i)
		delete body[i];
}

//Dodaje cia³o na pozycji x,y
void Snake::AddBody(int x, int y)
{
	Character* ch = new Character;
	ch->GetX() = x;
	ch->GetY() = y;
	ch->SetType(Types::Snake);

	body.push_back(ch);
}

//Dodaje cia³o na ogonie
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
	//sprawdzamy czy aktualnie porusza siê w lini poziomej
	if(xVector != 0)
		if (y != 0) //Jeœli u¿ytkownik chce skrêciæ w góre lub dó³
		{
			xVector = 0;
			yVector = y;
		}

	//sprawdzamy czy aktualnie porusza siê w lini pionowej
	if (yVector != 0)
		if (x != 0) // Jeœli u¿ytkownik chce skrêciæ w lewo lub prawo
		{ 
			xVector = x;
			yVector = 0;
		}

	COORD c;

	//usuwa ostatni kawa³ek wê¿a 
	//Jeœli doda³o cia³o nie usuwa ostatniego bloku 
	//poniwea¿ dodanie cia³a dodaje go na tej samej pozycji co ogon
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
	
	//zmienia pozycje wsyztkich elementów na pozycje nastêpnego elementu
	for (int i = body.size() - 2; i > 0; --i)
	{	
		body[i]->GetX() = body[i-1]->GetX();
		body[i]->GetY() = body[i-1]->GetY();
	}

	//przesuwa g³owe o nasz wektor przesuniecia
	body[0]->GetX() += xVector;
	body[0]->GetY() += yVector;

	c.X = body[0]->GetX();
	c.Y = body[0]->GetY();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	//rysuje now¹ g³owe
	putchar((char)Types::Snake);

	c.X = 0;
	c.Y = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

bool Snake::Collision()
{
	for (int i = 1; i < body.size(); i++)
	{
		//Jeœli nast¹pi³a kolizja cia³a wê¿a z g³ow¹ zwraca true
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