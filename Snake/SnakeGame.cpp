#include "SnakeGame.h"
#include "Game.h"
#include "Menu.h"
#include <Windows.h>
#include <iostream>
#include <time.h>

using namespace std;

SnakeGame::SnakeGame() 
	:board(20), //Wielkoœæ planszy 20x20
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

	//Krawêdzie planszy ustawiamy jako œciany
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

	//Powoduje ¿e funkcja rand nie zwraca ca³y czas tej samej liczby

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

		//Jeœli przegraliœmy to nie mo¿emy siê ruszaæ i ta funkcja koñczy siê w tym momencie 
		if (GameOver)
			return;

		if (GetAsyncKeyState(VK_UP)) // UP
		{
			snake.Move(0, -1); // idŸ w góre
		}
		else
		if (GetAsyncKeyState(VK_DOWN)) // DOWN
		{
			snake.Move(0, 1); // idŸ w dó³
		}
		else
		if (GetAsyncKeyState(VK_LEFT)) // LEFT
		{
			snake.Move(-1, 0); // idŸ w lewo
		}
		else
		if (GetAsyncKeyState(VK_RIGHT)) // RIGHT
		{
			snake.Move(1, 0); // idŸ w prawo
		}
		else
		snake.Move(0,0); //jeœli nic nie nacisneliœmy snake idze w kierunku w którym szed³ wczeœniej


		//Sprawdzamy czy po przesuniêciu wê¿a jego g³owa nie zderzy³a siê ze œcian¹
		int x = snake.GetFirst().GetX();
		int y = snake.GetFirst().GetY();
		Types t = board.GetType(x, y); //typ planszy na pozycji g³owy wê¿a

		if(t != Types::Empty) //Jeœli nie jest to pusty blok
		{
			if (t == Types::Food) // jeœli jest to jedzenie
			{
				//usuñ jedzenie z planszy
				board.SetType(x, y, Types::Empty);

				for (size_t i = 0; i < 3; i++)
				{
					if (food[i].X() == x && food[i].Y() == y)
						food[i].GenerateFood(&board);
				}

				//dodaj 1 do d³ugoœæi wê¿a
				snake.AddBody();

				//dodaj 1 score
				Score++;
			}
			else
			{
				//Jeœli nie by³o to jedzenie to przegraliœmy
				SetGameOver();
			}
		}

		//sprawdza czy nasz w¹¿ nie zde¿y³ siê ze swoim wlasnym cia³em
		if(snake.Collision())
			SetGameOver();
		

}

void SnakeGame::Draw()
{
	//rysuje plansze na starcie
	board.Draw();

	//rysuje wê¿a na starcie
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

	//wypisujemy GAME OVER mniej wiêcej na œrodku 
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


	//Ustawiamy kursor na pozycje 0 0 ¿eby nie miga³ na œrodku po wypisaniu PRESS ESC
	c.X = 0;
	c.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

