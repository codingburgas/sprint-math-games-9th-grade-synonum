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

int main() {
    while (true) {
		cout << "==============================\n";
		cout << "       Welcome to SynoNum!\n";
		cout << "==============================\n\n";
		cout << "Choose what you want to do:\n"
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
            break;

        case 4:
            cout << endl << "Redirecting you to the explanation page ..." << endl;
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
