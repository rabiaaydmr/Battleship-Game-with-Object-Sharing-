#include "Player.h"
#include "Board.h"
#include <iostream>
using namespace std;

Player::Player(Board &myboard,int id) //constructor
		:board(myboard), playerid(id)
		{}
bool Player::guess(int row,int col)
{
	return board.makeAHit(row,col);
}
bool Player::wins()
{
	return board.checkIfPlayerWon(playerid);
}





























