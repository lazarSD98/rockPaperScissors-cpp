#include <iostream>
#include <string>
#include <cctype>
#include "gameLogic.h"
 
int playerOneWins{ };
int playerTwoWins{  };
int draws{  };
const std::string playerOneVictory = "Player one victory!";
const std::string playerTwoVictory = "Player two victory!";
const std::string itsAtie = "It's a tie!";
const std::string youDidntEvenPlayGame = "You didn't even play the game :'( !";
const std::string starsAndLines = "- * - * - * - * - * - * - * - * - * - *";

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

void printWinner(const std::string& message) {
	std::cout << '\n' <<
		starsAndLines << '\n'
		<< '\n'
		<< '\n'
		<< message
		<< '\n'
		<< '\n'
		<< starsAndLines
		<< '\n';
}

void finalWinnerIs() {
	if (playerOneWins > playerTwoWins) {
		printWinner(playerOneVictory);
	}
	if (playerTwoWins > playerOneWins ) {
		printWinner(playerTwoVictory);
	}

	if (playerOneWins == playerTwoWins && (playerOneWins > 0 || playerTwoWins > 0 || draws > 0))
	{
		printWinner(itsAtie);
	
	}
	if (playerOneWins == 0 && playerTwoWins == 0 && draws == 0) {
		printWinner(youDidntEvenPlayGame);

	}
	
}





