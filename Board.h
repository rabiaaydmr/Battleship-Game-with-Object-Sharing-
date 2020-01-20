#ifndef _BOARD_H
#define _BOARD_H

class Board
{
	public:
		Board(); // default constructor
		void displayBoard(); // displays the board
		bool putShip(int,int,int,int,int,int); // creating ship
		bool makeAHit(int,int); // hitting the enemy ship
		bool checkIfPlayerWon(int); // check if the player won
	private:
		int theBoard[6][6]; // private matrix board created
};
#endif
