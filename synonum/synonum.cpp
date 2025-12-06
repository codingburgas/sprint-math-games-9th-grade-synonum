#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int hangingMan() {
	srand(time(0));

	string secretWords[100] = {
	"apple", "mirror", "light", "river", "breeze", "carpet", "galaxy", "thunder",
	"crystal", "meadow", "shadow", "enjoy", "horizon", "puzzle", "shelter", "compass",
	"fabric", "memory", "harbor", "whisper", "canyon", "blossom", "submit", "marble",
	"echo", "timber", "velvet", "orbit", "anchor", "lunch", "coral", "vessel",
	"nectar", "prism", "quill", "parchment", "ripple", "forest", "glimmer", "tapestry",
	"relic", "earth", "dune", "current", "cedar", "stream", "petal", "cavern",
	"starlight", "orchard", "lemon", "cradle", "summit", "willow", "oracle", "cream",
	"whale", "mother", "label", "driftwood", "terrace", "wander", "silo", "harvest",
	"forge", "shimmer", "dusk", "library", "bloom", "ash", "stone", "gully",
	"plume", "flourish", "moss", "grain", "pocket", "chair", "habit", "spark",
	"thread", "sunburn", "grove", "quartz", "house", "ember", "lantern", "brown",
	"gravel", "honey", "ticket", "place", "whole", "spruce", "cargo", "plastic"
	};

	char playAgain = 'Y';

	while (playAgain == 'Y' || playAgain == 'y') {

		string answer = secretWords[rand() % 100];
		string guessedWord(answer.length(), '_');
		int lives = 5;
		char guess;

		cout << "=== Hangman Game Started! ===\n\n";

		while (lives > 0 && guessedWord != answer) {
			cout << "Word: " << guessedWord << endl;
			cout << "Lives left: " << lives << endl;
			cout << "Enter a letter: ";
			cin >> guess;

			bool found = false;

			for (int i = 0; i < answer.length(); i++) {
				if (answer[i] == guess) {
					guessedWord[i] = guess;
					found = true;
				}
			}

			if (!found) {
				lives--;
				cout << "\nWrong letter!\n" << endl;


			}
		}



		if (guessedWord == answer) {
			cout << "You guessed the word: " << answer << endl;
		}
		else {
			cout << "You lost! The word was: " << answer << endl;
		}

		cout << "\nWould you like to play again? (Y/N): ";
		cin >> playAgain;
	}

	cout << "\nThank you for playing!\n";
	return 1;
}

int mathQuiz() {

	int numA[100]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int numB[100]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int a = 0;
	int b = 0;
	int answer = 0;
	int choice = 0;

	char playAgain = 'Y';

	while (playAgain == 'Y' || playAgain == 'y') {

		int lives = 5;
		bool validChoice = false;

		while (validChoice == false) {

			cout << "=== Math Quiz ===\n\n";
			cout << "Select a mode:\n"
				<< "1. Addition\n"
				<< "2. Subtraction\n"
				<< "3. Multiplication\n"
				<< "4. Division\n\n";
			cin >> choice;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
				cout << "\nInvalid choice. Please select a valid game mode.\n";
			}
			else {
				validChoice = true;
				cout << "\nYou have selected game mode " << choice << ".\n";
			}
		}

		if (choice == 1) {

			cout << "Starting Addition Game...\n";

			while (lives > 0) {
				a = numA[rand() % 10];
				b = numB[rand() % 10];

				cout << "\nWhat is " << a << " + " << b << " ?\n";
				cin >> answer;

				if (answer == a + b) {
					cout << "Correct!\n";
				}
				else {
					cout << "Incorrect. The correct answer is " << a + b << ".\n";
					--lives;
					cout << "Lives remaining: " << lives << ".\n";
				}
			}

			if (lives == 0) {
				cout << "Game Over! You've run out of lives.\nWould you like to play again? If so, enter Y or y.\n";
				cin >> playAgain;
			}
		}

		else if (choice == 2) {

			cout << "Starting Subtraction Game...\n";

			while (lives > 0) {
				a = numA[rand() % 10];
				b = numB[rand() % 10];

				cout << "\nWhat is " << a << " - " << b << " ?\n";
				cin >> answer;

				if (answer == a - b) {
					cout << "Correct!\n";
				}
				else {
					cout << "Incorrect. The correct answer is " << a - b << ".\n";
					--lives;
					cout << "Lives remaining: " << lives << ".\n";
				}
			}

			if (lives == 0) {
				cout << "Game Over! You've run out of lives.\nWould you like to play again? If so, enter Y or y.\n";
				cin >> playAgain;
			}

		}
		else if (choice == 3) {

			cout << "Starting Multiplication Game...\n";

			while (lives > 0) {
				a = numA[rand() % 10];
				b = numB[rand() % 10];

				cout << "\nWhat is " << a << " * " << b << " ?\n";
				cin >> answer;

				if (answer == a * b) {
					cout << "Correct!\n";
				}
				else {
					cout << "Incorrect. The correct answer is " << a * b << ".\n";
					--lives;
					cout << "Lives remaining: " << lives << ".\n";
				}
			}

			if (lives == 0) {
				cout << "Game Over! You've run out of lives.\nWould you like to play again? If so, enter Y or y.\n";
				cin >> playAgain;
			}

		}
		else if (choice == 4) {

			cout << "Starting Division Game...\n";

			while (lives > 0) {
				a = numA[rand() % 10];
				b = numB[rand() % 10];

				cout << "\nWhat is " << a << " / " << b << " ?\n";
				cin >> answer;

				if (answer == a / b) {
					cout << "Correct!\n";
				}
				else {
					cout << "Incorrect. The correct answer is " << a / b << ".\n";
					--lives;
					cout << "Lives remaining: " << lives << ".\n";
				}
			}

			if (lives == 0) {
				cout << "\nGame Over! You've run out of lives.\nWould you like to play again? If so, enter Y or y.\n";
				cin >> playAgain;
			}

		}

	}

	cout << "Good Game! See you next time.\n";
	return 0;

}
int help() {
	cout << "\n=== Help ===\n\n";

	cout << "This page will help you understand how to use SynoNum.\n\n";

	cout << "1. Navigating the Menu\n\n";
	cout << "= When the main menu appears, type the number of the\n";
	cout << "  option you want (1–5) and press Enter.\n";
	cout << "= Example: To start word games, type 2 and press Enter.\n\n";

	cout << "2. Entering Answers\n";
	cout << "----------------------------------------\n";
	cout << "= For the maths game, type your answer as a number.\n";
	cout << "= For the word game, type a single letter.\n";
	cout << "= Make sure you press Enter after every input.\n\n";

	cout << "3. Handling Invalid Input\n";
	cout << "----------------------------------------\n";
	cout << "= If you enter something that isn't a number when one\n";
	cout << "  is required, the program will reset the input and ask\n";
	cout << "  you again.\n";
	cout << "= If you mistype a menu number, the program will ask\n";
	cout << "  you to choose between 1 and 5.\n\n";

	cout << "4. Returning to the Menu\n";
	cout << "----------------------------------------\n";
	cout << "= After you finish a game, you will be asked if you\n";
	cout << "  want to play again.\n";
	cout << "= If you enter N, the game returns you to the main menu.\n\n";

	cout << "5. Exiting the Program\n";
	cout << "----------------------------------------\n";
	cout << "= To exit, simply choose option 5 from the main menu.\n";
	cout << "= This safely closes SynoNum.\n\n";

	cout << "If you still need help, please consult the\n";
	cout << "Read About the Games section (option 4).\n\n";

	cout << "Press any key and hit Enter to return to the main menu... ";
	string temp;
	cin >> temp;

	return 0;
}

int readAboutTheGames() {
	cout << "\n=== About the Games ===\n\n";

	cout << "1. Maths Games\n";
	cout << "----------------------------------------\n";
	cout << "= The Maths Quiz includes four modes:\n";
	cout << " - Addition: Solve random addition problems.\n";
	cout << " - Subtraction: Solve random subtraction problems.\n";
	cout << " - Multiplication: Solve multiplication exercises.\n";
	cout << " - Division: Solve simple division problems.\n";
	cout << "= You start with 5 lives. Each incorrect answer removes one life.\n";
	cout << "= The goal is to answer as many questions correctly as possible.\n\n";

	cout << "2. Word Games (Hangman)\n";
	cout << "----------------------------------------\n";
	cout << "= A random word is selected, and you must guess it one letter\n";
	cout << "  at a time.\n";
	cout << "= Each wrong guess costs you a life. You have 5 lives in total.\n";
	cout << "= If you reveal all letters, you win.\n";
	cout << "= If you lose all lives, the game ends.\n\n";

	cout << "Both game modes are designed for fun and practice in a simple, friendly way!\n\n";

	cout << "Press any key and hit Enter to return to the main menu... ";
	string temp;
	cin >> temp;

	return 0;
}

int main() {
	while (true) {
		cout << "==============================\n";
		cout << "     Welcome to SynoNum!\n";
		cout << "==============================\n\n";
		cout << "Choose what you want to do:\n";
		cout << " 1. Maths games" << endl;
		cout << " 2. Word games" << endl;
		cout << " 3. Help" << endl;
		cout << " 4. Read about the games" << endl;
		cout << " 5. Exit" << endl << endl;
		cout << "Your answer here: ";

		int option;
		cin >> option;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Please enter a number: ";
			continue;
		}

		switch (option) {
		case 1:
			cout << endl << "Redirecting you to the list of the maths games ..." << endl;
			mathQuiz();
			break;

		case 2:
			cout << endl << "Redirecting you to the list of the word games ..." << endl;
			hangingMan();
			break;

		case 3:
			cout << endl << "Redirecting you to the help page ..." << endl;
			help();
			break;

		case 4:
			cout << endl << "Redirecting you to the explanation page ..." << endl;
			readAboutTheGames();
			break;

		case 5:
			cout << endl << "Shutting down the programme ... Goodbye!";
			return 0;

		default:
			cout << endl << "Please choose a valid option (1-5): ";
			break;
		}
	}
}