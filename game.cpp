#include <iostream>
#include <string>
#include <cctype>
#include "gameLogic.h"
 
int playerOneWins{ };
int playerTwoWins{  };
int draws{  };

void letsPlayPvp() {
	int winner = whoIsTheWinnerPvp();

	if (winner == 1) {
		++draws;
	}
	else if (winner == 2) {
		++playerOneWins;
	}
	else if (winner == 3) {
		++playerTwoWins;
	}
}


void doYouWantToPlayAgain() {
	bool isTrue = letsPlayAgain();
	while (isTrue == true) {
		letsPlayPvp();
		isTrue = letsPlayAgain();
	}
}

void finalWinnerIs() {
	if (playerOneWins > playerTwoWins) {
		std::cout << std::endl;
		std::cout << "- * - * - * - * - * - * - * - * - * - *" << std::endl;
		std::cout << std::endl;
		std::cout << "PLayer one victory!" << std::endl;
		std::cout << std::endl;
		std::cout << "- * - * - * - * - * - * - * - * - * - *" << std::endl;
	}
	if (playerTwoWins > playerOneWins ) {
		std::cout << std::endl;
		std::cout << "- * - * - * - * - * - * - * - * - * - *" << std::endl;
		std::cout << std::endl;
		std::cout << "Player two victory!" << std::endl;
		std::cout << std::endl;
		std::cout << "- * - * - * - * - * - * - * - * - * - *" << std::endl;
	}

	if (playerOneWins == playerTwoWins && (playerOneWins > 0 || playerTwoWins > 0 || draws > 0))
	{
		std::cout << std::endl;
		std::cout << "- * - * - * - * - * - * - * - * - * - *" << std::endl;
		std::cout << std::endl;
		std::cout << "It's a draw!" << std::endl;
		std::cout << std::endl;
		std::cout << "- * - * - * - * - * - * - * - * - * - *" << std::endl;
	
	}
	if (playerOneWins == 0 && playerTwoWins == 0 && draws == 0) {
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "You didn't even play the game :'( !" << std::endl;
		std::cout << std::endl;

	}
	
}





