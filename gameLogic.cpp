#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <conio.h>
#include "game.h"


std::string trim(const std::string& str);

const std::string DO_YOU_WANT_TO_PLAY_AGAIN = "Do you want to play again?";

const std::string firstPlayerTurn = "Player 1 turn!";
const std::string secondPlayerTurn = "Player 2 turn!";
const std::string pleaseEnterValue = "Please enter Rock, Paper or Scissors!";
const std::string thanksForPlaying = "Thanks for playing!";

std::string hiddenInput() {
	std::string input;
	char ch;

	while (true) {
		ch = _getch();
		if (ch == '\r') {
			std::cout << std::endl;
			std::cout << "Booo its hidden" << std::endl;
			std::cout << std::endl;
			break;
		}
		else if (ch == '\b') {
			if (!input.empty()) {
				input.pop_back();
			}
		}
		else if (ch == 0 || ch == -32) {
			_getch();
		}
		else {
			input.push_back(ch);
		}
	}

	return input;
}

std::string playerInput() {
	std::string playerOption;
	while (true)
	{
		playerOption = hiddenInput();
		for (char& c : playerOption) {
			c = tolower(c);
		}

		playerOption = trim(playerOption);

			if (playerOption == "rock" || playerOption == "paper" || playerOption == "scissors" || playerOption == "exit") {
				return trim(playerOption);
			
			
		}

		std::cout << "Invalid option. Try again! " << std::endl;
	}

}

char playerInputChar() {
	std::string value = playerInput();
	char first = value[0];
	char finalValue =
		(first == 'r') ? 1 :
		(first == 'p') ? 2 :
		(first == 's') ? 3 :
		(first == 'e') ? 4 : 0;
	if (first == 'e') {
		finalWinnerIs();
		std::exit(0);

	}

	return finalValue;
}

char playerOneInput() {
	std::cout << firstPlayerTurn << std::endl;
	std::cout << pleaseEnterValue << std::endl;
	return playerInputChar();
}

char playerTwoInput() {
	std::cout << secondPlayerTurn << std::endl;
	std::cout << pleaseEnterValue << std::endl;
	return playerInputChar();
}

int whoIsTheWinnerPvp() {
	char playerOneInputFinal = playerOneInput();
	char playerTwoInputFinal = playerTwoInput();

	int result = (playerOneInputFinal - playerTwoInputFinal + 3) % 3;

	if (result == 0) {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Tie!" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		return 1;
	}
	else if (result == 1) {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Player 1 wins!" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		return 2;
	}
	else {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Player 2 wins!" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		return 3;
	}
}

bool letsPlayAgain() {
	std::string choice;
	std::cout << DO_YOU_WANT_TO_PLAY_AGAIN << std::endl;
	std::getline(std::cin, choice);
	for (char& c : choice) {
		c = tolower(c);
	}
	while (choice != "yes" && choice != "no") {
		std::cout << "Invalid choice, choose again" << std::endl;
		std::getline(std::cin, choice);
		for (char& c : choice) {
			c = tolower(c);
		}
	}
	if (choice == "yes") {
		return true;
	}
	if (choice == "no") {
		return false;
	}
}



std::string trim(const std::string& str) {
	size_t start = 0;
	while (start < str.size() && std::isspace(str[start])) ++start;

	size_t end = str.size();
	while (end > start && std::isspace(str[end - 1])) --end;

	return str.substr(start, end - start);
}

