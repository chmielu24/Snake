#include "SnakeGame.h"
#include "Game.h"
#include "Menu.h"
#include <Windows.h>
#include <iostream>
#include <time.h>

using namespace std;

SnakeGame::SnakeGame() 
	:board(20), //Wielko�� planszy 20x20
	GameOver(false)
{
	int plansza;

	cout << "Podaj plansze 1-4\n";
	cin >> plansza;

	if (plansza < 1)
		plansza = 1;
	if(plansza > 4)
		plansza = 4;


	int PlaneType[4][20][20] = {

		{
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
		},

		{
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
		},

		{
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
		},

		{
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
		},

	};

	//Kraw�dzie planszy ustawiamy jako �ciany
	for(int x=0; x < board.GetSize(); ++x)
		for (int y = 0; y < board.GetSize(); ++y)
		{	
			if (x == 0 || y == 0 || x == board.GetSize()-1 || y == board.GetSize()-1)
				board.SetType(x, y, Types::Wall);
			else
			{
				if(PlaneType[plansza-1][y][x] == 1)
					board.SetType(x, y, Types::Wall);
				else
					board.SetType(x, y, Types::Empty);

			}
		}

	//Powoduje �e funkcja rand nie zwraca ca�y czas tej samej liczby

	//na start tworzymy 3x jedzenie na planszy
	for (int i = 0; i < 3; i++)
	food[i].GenerateFood(&board);
}


SnakeGame::~SnakeGame()
{
}


void SnakeGame::Update()
{

		if (GetAsyncKeyState(VK_ESCAPE)) //ESC
		{
			//wczytuje scene menu
			Game::Instance().LoadScene(new Menu());
		}

		//Je�li przegrali�my to nie mo�emy si� rusza� i ta funkcja ko�czy si� w tym momencie 
		if (GameOver)
			return;

		if (GetAsyncKeyState(VK_UP)) // UP
		{
			snake.Move(0, -1); // id� w g�re
		}
		else
		if (GetAsyncKeyState(VK_DOWN)) // DOWN
		{
			snake.Move(0, 1); // id� w d�
		}
		else
		if (GetAsyncKeyState(VK_LEFT)) // LEFT
		{
			snake.Move(-1, 0); // id� w lewo
		}
		else
		if (GetAsyncKeyState(VK_RIGHT)) // RIGHT
		{
			snake.Move(1, 0); // id� w prawo
		}
		else
		snake.Move(0,0); //je�li nic nie nacisneli�my snake idze w kierunku w kt�rym szed� wcze�niej


		//Sprawdzamy czy po przesuni�ciu w�a jego g�owa nie zderzy�a si� ze �cian�
		int x = snake.GetFirst().GetX();
		int y = snake.GetFirst().GetY();
		Types t = board.GetType(x, y); //typ planszy na pozycji g�owy w�a

		if(t != Types::Empty) //Je�li nie jest to pusty blok
		{
			if (t == Types::Food) // je�li jest to jedzenie
			{
				//usu� jedzenie z planszy
				board.SetType(x, y, Types::Empty);

				for (size_t i = 0; i < 3; i++)
				{
					if (food[i].X() == x && food[i].Y() == y)
						food[i].GenerateFood(&board);
				}

				//dodaj 1 do d�ugo��i w�a
				snake.AddBody();

				//dodaj 1 score
				Score++;
			}
			else
			{
				//Je�li nie by�o to jedzenie to przegrali�my
				SetGameOver();
			}
		}

		//sprawdza czy nasz w�� nie zde�y� si� ze swoim wlasnym cia�em
		if(snake.Collision())
			SetGameOver();
		

}

void SnakeGame::Draw()
{
	//rysuje plansze na starcie
	board.Draw();

	//rysuje w�a na starcie
	snake.Draw();
}

void SnakeGame::SetGameOver()
{
	//przegrana
	COORD c;
	c.X = snake.GetFirst().GetX();
	c.Y = snake.GetFirst().GetY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	putchar('x'); // w miejscu kolizji rysujemy x

	GameOver = true;

	//wypisujemy GAME OVER mniej wi�cej na �rodku 
	c.X = 5;
	c.Y = 5;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	cout << "GAME OVER";

	c.X = 5;
	c.Y = 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	cout << "SCORE: " << Score;
	c.X = 5;
	c.Y = 7;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	cout << "PRESS ESC";


	//Ustawiamy kursor na pozycje 0 0 �eby nie miga� na �rodku po wypisaniu PRESS ESC
	c.X = 0;
	c.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

