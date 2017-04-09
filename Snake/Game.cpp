#include "Game.h"
#include "Menu.h"
#include <Windows.h>
#include <iostream>

using namespace std;


void Game::Start()
{
	//Wczytujemy scene menu na starcie 
	LoadScene(new Menu());

	//jeœli aplikacja jest w³¹cznona to wykonujemy w nieskoñczonoœæ 
	while (isOpen)
	{
		//Aktualizacja sceny co klatke
		AccualScene->Update();

		//usypisamy na 250 ms ¿eby gra nie dzia³a³a zbyt szybko
		Sleep(250);
	}
}


void Game::LoadScene(iScene *newScene)
{
	//Usuwamy aktualn¹ scene
	delete AccualScene;

	//Przypisujemy now¹ scene
	AccualScene = newScene;

	//Czyœcimy ekran
	system("cls");
	//Rysujemy nasz¹ now¹ scene
	AccualScene->Draw();
}

Game::~Game()
{
	//Destruktor sprz¹ta po obiekcie
	delete AccualScene;
}

Game::Game()
{
	isOpen = true;
}

void Game::Exit()
{
	//Koniec Gry
	system("cls");
	cout << "Goodbye !\n";
	Sleep(1000);
	isOpen = false;
}