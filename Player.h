#ifndef PLAYER_H
#define PLAYER_h
#include "Board.h"

class Player
{
	public:
		Player(Board&,int);  //constructor
		bool guess(int,int); // returns true if player hit correct location
		bool wins(); // returns true if player won
	private:
		Board &board; // reference shared board object
		int playerid; // player id
};
#endif
