#include "Board.h"



Board::Board(int size)
{
	Size = size;

	//Na pocz�tku tworzymy nasz� tablice 2D blok�w (character - znak)
	board = new Character*[size];
	for (int x = 0; x < Size; ++x)
		board[x] = new Character[size];

	//Ka�demu blokowi ustalamy pozyj� na kt�rej ma on by� wy�wietlany
	for (int x = 0; x < Size; ++x)
		for (int y = 0; y < Size; ++y)
		{
			board[x][y].GetX() = x;
			board[x][y].GetY() = y;
		}



}


Board::~Board()
{
	//sprz�tamy po obiekcie
	for (int x = 0; x < Size; ++x)
		delete[] board[x];

	delete[] board;
}


void Board::Draw()
{
	for(int x = 0; x < Size; ++x)
		for (int y = 0; y < Size; ++y)
		{
			board[x][y].Draw();
		}

}

void Board::Draw(int x, int y)
{
		board[x][y].Draw();
}


void Board::DrawFood()
{
	//Je�li typ blokou na pozycji x,y to jedzenie to narysuj je
	for (int x = 0; x < Size; ++x)
		for (int y = 0; y < Size; ++y)
			if(board[x][y].GetType() == Types::Food)
				board[x][y].Draw();
}