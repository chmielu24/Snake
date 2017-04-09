#include "Game.h"
#include "Menu.h"
#include <Windows.h>
#include <iostream>

using namespace std;


void Game::Start()
{
	//Wczytujemy scene menu na starcie 
	LoadScene(new Menu());

	//je�li aplikacja jest w��cznona to wykonujemy w niesko�czono�� 
	while (isOpen)
	{
		//Aktualizacja sceny co klatke
		AccualScene->Update();

		//usypisamy na 250 ms �eby gra nie dzia�a�a zbyt szybko
		Sleep(250);
	}
}


void Game::LoadScene(iScene *newScene)
{
	//Usuwamy aktualn� scene
	delete AccualScene;

	//Przypisujemy now� scene
	AccualScene = newScene;

	//Czy�cimy ekran
	system("cls");
	//Rysujemy nasz� now� scene
	AccualScene->Draw();
}

Game::~Game()
{
	//Destruktor sprz�ta po obiekcie
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