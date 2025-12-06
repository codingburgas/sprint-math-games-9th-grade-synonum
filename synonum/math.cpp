#include <iostream>
#include <string>
using namespace std;

int main() {

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

			cout << "Welcome! You have started a new game.\nPlease choose a number corresponding to the game mode you want to play: \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division \n";
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

		} else if (choice == 4) {
			
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