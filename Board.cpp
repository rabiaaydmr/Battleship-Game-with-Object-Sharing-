#include "Board.h"
#include <iostream>
#include <iomanip>
using namespace std;

Board::Board() // all elements of matrix set to 0
{
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			theBoard[i][k] = 0;
		}
	}
}
void Board::displayBoard()
{
	cout << setw(9) << "P1" << setw(7) << "|" << setw(9) << "P2" << endl;
	cout << setw(4);
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			cout << theBoard[i][k] << setw(4);
			if (k==2)
			{
				cout << "|" << setw(4);;
			}
		}
		cout << endl << setw(4);
	}
}

bool Board::putShip(int player,int ship, int rowStart, int colStart, int rowEnd, int colEnd)
{
	int rowlength = rowEnd - rowStart;
	int collength = colEnd - colStart;
	if (rowlength<0)
		rowlength = 0 - rowlength;
	if (collength<0)
		collength = 0 - collength;

	if (ship == 1)
	{
		if ((rowlength == 0 && collength == 1 ) || (collength == 0 && rowlength == 1))
		{
			if ((player == 1 && (rowStart>=0 && rowEnd<6 && colStart>=0 && colEnd<3)) || (player == 2 && (rowStart>=0 && rowEnd<6 && colStart>2 && colEnd<6)))
			{
				if (theBoard[rowStart][colStart] == 0 && theBoard[rowEnd][colEnd] == 0)
				{
					theBoard[rowStart][colStart] = 1;
					theBoard[rowEnd][colEnd] = 1;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
	{
		if (rowlength == 0 && collength == 2)
		{
			if ((player == 1 && (rowStart>=0 && rowEnd<6 && colStart>=0 && colEnd<3)) || (player == 2 && (rowStart>=0 && rowEnd<6 && colStart>2 && colEnd<6)))
			{
				if (theBoard[rowStart][colStart] == 0 && theBoard[rowEnd][colEnd] == 0 && theBoard[rowStart][colStart+1] == 0)
				{
					theBoard[rowStart][colStart] = 1;
					theBoard[rowEnd][colEnd] = 1;
					theBoard[rowStart][colStart+1] = 1;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else if (collength == 0 && rowlength == 2)
		{
			if ((player == 1 && (rowStart>=0 && rowEnd<6 && colStart>=0 && colEnd<3)) || (player == 2 && (rowStart>=0 && rowEnd<6 && colStart>2 && colEnd<6)))
			{
				if (theBoard[rowStart][colStart] == 0 && theBoard[rowEnd][colEnd] == 0 && theBoard[rowStart+1][colStart] == 0)
				{
					theBoard[rowStart][colStart] = 1;
					theBoard[rowEnd][colEnd] = 1;
					theBoard[rowStart+1][colStart] = 1;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
}

bool Board::makeAHit(int row,int col)
{
	if (theBoard[row][col] == 1)
	{
		theBoard[row][col] = -1; // change the value if it hits
		return true;
	}
	else
	{
		return false;
	}
}
bool Board::checkIfPlayerWon(int player) 
{
	if (player == 2) // if player 2, check player 1's board
	{
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 6; k++)
			{
				if (theBoard[k][i] == 1)
				{
					return false;
				}
			}
		}
		return true;
	}
	else if(player == 1) // if player 1, check player 2's board
	{
		for (int i = 3; i < 6; i++)
		{
			for (int k = 0; k < 6; k++)
			{
				if (theBoard[k][i] == 1)
				{
					return false;
				}
			}
		}
		return true;
	}
}














