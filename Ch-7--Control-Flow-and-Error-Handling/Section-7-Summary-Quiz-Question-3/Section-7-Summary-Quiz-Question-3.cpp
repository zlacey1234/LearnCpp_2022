#include <iostream>
#include <random>

int ReadUserGuess() {
	int user_guess{};
	std::cin >> user_guess;
	return user_guess;
}

void PlayGame(int number_guesses, int answer) {
	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have " <<
		number_guesses << " tries to guess what it is.\n";

	for (int guess_idx{ 1 }; guess_idx <= number_guesses; ++guess_idx) {
		std::cout << "Guess #" << guess_idx << ": ";
		int current_guess{ ReadUserGuess() };

		if (current_guess == answer) {
			std::cout << "Correct! You win!\n";
			break;
		}
		else if (current_guess < answer) {
			std::cout << "Your guess is too low.\n";
		}
		else {
			std::cout << "Your guess is too high.\n";
		}
	}
}

bool CheckToPlayAgain() {
	std::cout << "Would you like to play again (y/n)? ";
	char play_again_answer{};
	std::cin >> play_again_answer;

	switch (play_again_answer)
	{
	case 'y':
		return true;
	case 'n':
		return false;
	default:
		break;
	}

	return false;
}

int main() {
	std::random_device rd;
	std::seed_seq seq{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 mt{ seq };
	std::uniform_int_distribution die{ 1, 100 };

	constexpr int guesses{ 7 };
	bool want_to_play{ true };

	do {
		int answer{ die(mt) };

		std::cout << answer << "\n";

		PlayGame(guesses, answer);

		want_to_play = CheckToPlayAgain();

	} while (want_to_play);

	return 0;
}
