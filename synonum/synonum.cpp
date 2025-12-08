#include <iostream>
#include <string>

using namespace std;

int hangingMan() { // Create a function for the hangman game

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

	string playAgain = "Yes";

	while (playAgain == "Yes" || playAgain == "yes") { 

		string answer = secretWords[rand() % 100]; // Select a random word from the array
		string guessedWord(answer.length(), '_'); // Create a string of underscores with the same length as the answer
		int lives = 5;
		char guess;

		cout << "\n=== Hangman Game Started! ===\n\n";

		while (lives > 0 && guessedWord != answer) { // Creates a loop that continues until the player runs out of lives or guesses the word
			cout << "Word: " << guessedWord << endl;
			cout << "----------------------------------------\n";
			cout << "Lives remaining: " << lives << endl;

			string input;
			while (true) {
				cout << "\nEnter a letter: ";
				cin >> input;
				cout << "\n";

				if (input.length() != 1 || !isalpha(input[0])) { // Check if the input is a single letter
					system("cls");
					cout << "\nInvalid input. Please enter a single letter!\n";
					cin.clear(); // Clear the error flag on cin
					cin.ignore(10000, '\n'); // Discard invalid input
				}
				else {
					guess = tolower(input[0]); // Convert the input to lowercase
					break;
				}
			}


			bool found = false;

			for (int i = 0; i < answer.length(); i++) { // Check if the guessed letter is in the answer
				if (answer[i] == guess) {
					guessedWord[i] = guess;
					found = true;
				}
			}

			if (!found) {
				lives--;
				cout << "Wrong letter!\n" << endl;


			}
		}

		if (guessedWord == answer) {
			cout << "Good job! You guessed the word: " << answer << endl;
		}
		else {
			cout << "You lost! The word was: " << answer << endl;
		}

		cout << "----------------------------------------\n";

		while (true) { // A loop to ask the player if they want to play again
			cout << "\nWould you like to play again?\n";
			cout << " - Yes\n";
			cout << " - No\n";
			cout << "Your answer here: ";
			cin >> playAgain;

			string playAgainLower = playAgain; // Create a new string variable to store the lowercase version of playAgain
			for (char& c : playAgainLower) c = tolower(c); // Convert the string to lowercase

			if (playAgainLower == "yes") {
				system("cls");
				break; // Exit the loop to replay the game
			}
			else if (playAgainLower == "no") {
				system("cls");
				return 1; // Exit the function
			}
			else {
				cout << "\nWrong input, try again.\n"; 
			}
		}

	}

	cout << "\nThank you for playing!\n";
	system("cls");
	return 1;
}

int mathQuiz() { // Create a function for the math quiz game

	double numA[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // Create two arrays of numbers to use in the math problems
	double numB[10]={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	double a = 0;
	double b = 0;
	double answer = 0;
	int choice = 0;

	string playAgain = "Yes";

	while (playAgain == "Yes" || playAgain == "yes") { // Set a cycle for replaying the game

		int lives = 5;
		bool validChoice = false;

		while (validChoice == false) {

			if (cin.fail()) { // Check for invalid input
				cin.clear(); // Clear the error flag on cin
				cin.ignore(10000, '\n'); // Discard invalid input
				system("cls"); // Clear the console
				cout << "\nInvalid input. Please enter a number!\n";
				continue;
			}

			cout << "\nStarting Math Quiz ...\n\n"; //cout << "\n=== Math Quiz Started! ===\n\n";
			cout << "Select a mode:\n";
			cout << "1. Addition\n";
			cout << "2. Subtraction\n";
			cout << "3. Multiplication\n";
			cout << "4. Division\n\n";

			cout << "Enter your answer: ";
			cin >> choice;
			system("cls");

			if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
				cout << "\nInvalid input. Please enter a number! \n";
			}
			else {
				validChoice = true;
			}
		}

		if (choice == 1) {

			cout << "\n=== Addition Game started! ===\n";

			while (lives > 0) {
				a = numA[rand() % 10]; // Select two random numbers from the arrays
				b = numB[rand() % 10];

				cout << "\nWhat is " << a << " + " << b << " ?\n";
				cout << "----------------------------------------\n";
				cout << "Lives remaining: " << lives << "\n\n";
				cout << "Enter your answer: ";
				cin >> answer;

				if (cin.fail()) { // Check for invalid input
					cin.clear();
					cin.ignore(10000, '\n');
					system("cls");
					cout << "Invalid input. Please enter a number!\n";
					continue; // Restart the loop
				}

				if (answer == a + b) {
					cout << "\nCorrect!\n";
					cout << "----------------------------------------\n";
					cout << "Lives remaining: " << lives << "\n";
				}
				else {
					cout << "\nIncorrect. The correct answer is " << a + b << "\n";
					cout << "----------------------------------------\n";
					--lives;
					cout << "Lives remaining: " << lives << "\n";
				}
			}

			if (lives == 0) {
				cout << "\nGame Over! You've run out of lives.";
				cout << "\n----------------------------------------\n";

				while (true) {
					cout << "\nWould you like to play again?\n";
					cout << " - Yes\n";
					cout << " - No\n";
					cout << "Your answer here: ";
					cin >> playAgain;

					string playAgainLower = playAgain;
					for (char& c : playAgainLower) c = tolower(c); // Convert the string to lowercase

					if (playAgainLower == "yes") {
						system("cls");
						break; // Exit the loop to replay the game
					}
					else if (playAgainLower == "no") {
						system("cls");
						return 1; // Exit the function
					}
					else {
						cout << "\nWrong input, try again.\n";
					}
				}
			}
		}

		else if (choice == 2) {

			cout << "\n=== Subtraction Game started! ===\n"; 

			while (lives > 0) { 
				a = numA[rand() % 10];
				b = numB[rand() % 10];

				cout << "\nWhat is " << a << " - " << b << " ?\n";
				cout << "----------------------------------------\n";
				cout << "Lives remaining: " << lives << "\n\n";
				cout << "Enter your answer: ";
				cin >> answer;

				if (cin.fail()) { // Check for invalid input
					cin.clear();
					cin.ignore(10000, '\n');
					system("cls");
					cout << "\nInvalid input. Please enter a number!\n";
					continue;
				}

				if (answer == a - b) {
					cout << "\nCorrect!\n";
					cout << "----------------------------------------\n";
					cout << "Lives remaining: " << lives << "\n";
				}
				else {
					cout << "\nIncorrect. The correct answer is " << a - b << ".\n";
					cout << "----------------------------------------\n";
					--lives;
					cout << "Lives remaining: " << lives << ".\n";
				}
			}

			if (lives == 0) {
				cout << "\nGame Over! You've run out of lives.";
				cout << "\n----------------------------------------\n";
				
				while (true) {
					cout << "\nWould you like to play again?\n";
					cout << " - Yes\n";
					cout << " - No\n";
					cout << "Your answer here: ";
					cin >> playAgain;

					string playAgainLower = playAgain; 
					for (char& c : playAgainLower) c = tolower(c); // Convert the string to lowercase

					if (playAgainLower == "yes") {
						system("cls");
						break;
					}
					else if (playAgainLower == "no") {
						system("cls");
						return 1;
					}
					else {
						cout << "\nWrong input, try again.\n";
					}
				}

			}

		}
		else if (choice == 3) {

			cout << "\n=== Multiplication Game started! ===\n";

			while (lives > 0) {
				a = numA[rand() % 10]; // Select two random numbers from the arrays
				b = numB[rand() % 10];

				cout << "\nWhat is " << a << " * " << b << " ?\n";
				cout << "----------------------------------------\n";
				cout << "Lives remaining: " << lives << "\n\n";
				cout << "Enter your answer: ";
				cin >> answer;

				if (cin.fail()) { // Check for invalid input
					cin.clear();
					cin.ignore(10000, '\n');
					system("cls");
					cout << "Invalid input. Please enter a number!\n";
					continue; // Restart the loop
				}

				if (answer == a * b) {
					cout << "\nCorrect!\n";
					cout << "----------------------------------------\n";
					cout << "Lives remaining: " << lives << "\n";
				}
				else {
					cout << "\nIncorrect. The correct answer is " << a * b << "\n";
					cout << "----------------------------------------\n";
					--lives;
					cout << "Lives remaining: " << lives << "\n";
				}
			}

			if (lives == 0) {
				cout << "\nGame Over! You've run out of lives.";
				cout << "\n----------------------------------------\n";
				
				while (true) {
					cout << "\nWould you like to play again?\n";
					cout << " - Yes\n";
					cout << " - No\n";
					cout << "Your answer here: ";
					cin >> playAgain;

					string playAgainLower = playAgain; // Create a new string variable to store the lowercase version of playAgain
					for (char& c : playAgainLower) c = tolower(c); // Convert the string to lowercase

					if (playAgainLower == "yes") {
						system("cls");
						break; 
					}
					else if (playAgainLower == "no") {
						system("cls");
						return 1;
					}
					else {
						cout << "\nWrong input, try again.\n";
					}
				}

			}

		}
		else if (choice == 4) {

			cout << "\n=== Division Game started! ===\n"; 

			while (lives > 0) { // Loop until the player runs out of lives
				a = numA[rand() % 10]; // Select two random numbers from the arrays
				b = numB[rand() % 10];

				cout << "\nWhat is " << a << " / " << b << " ?\n";
				cout << "----------------------------------------\n";
				cout << "Lives remaining: " << lives << "\n\n";
				cout << "Enter your answer: ";
				cin >> answer; 

				if (cin.fail()) { // Check for invalid input
					cin.clear();
					cin.ignore(10000, '\n');
					system("cls");
					cout << "\nInvalid input. Please enter a number!\n";
					continue; // Restart the loop
				}

				if (answer == a / b) {
					cout << "\nCorrect!\n";
					cout << "----------------------------------------\n";
					cout << "Lives remaining: " << lives << "\n";
				}
				else {
					cout << "\nIncorrect. The correct answer is " << a / b << ".\n";
					cout << "----------------------------------------\n";
					--lives; // Decrease lives by 1 for an incorrect answer
					cout << "Lives remaining: " << lives << "\n";
				}
			}

			if (lives == 0) { // If the player runs out of lives, end the game
				cout << "\nGame Over! You've run out of lives.";
				cout << "\n----------------------------------------\n";
				
				while (true) {
					cout << "\nWould you like to play again?\n";
					cout << " - Yes\n";
					cout << " - No\n";
					cout << "Your answer here: ";
					cin >> playAgain;

					string playAgainLower = playAgain; // Create a new string variable to store the lowercase version of playAgain
					for (char& c : playAgainLower) c = tolower(c); // Convert the string to lowercase

					if (playAgainLower == "yes") {
						system("cls");
						break; // Exit the loop to replay the game
					}
					else if (playAgainLower == "no") {
						system("cls");
						return 1; // Exit the function
					}
					else {
						cout << "\nWrong input, try again.\n";
					}
				}

			}

		}

	}

	cout << "Good Game! See you next time.\n";
	system("cls");
	return 1;

}

int guessNumber() { // Create a function for guess the number game
	int guessNum[100] = { 1, 32, 69, 5, 77, 13, 25, 100, 42, 67 }; // Create an array of 10 random numbers

	int num = 0;
	int guess = 0;

	string playAgain = "Yes";

	while (playAgain == "Yes" || playAgain == "yes") { // Set a cycle for replaying the game

		int lives = 5;

		cout << "\n=== Guess the Number Game started! ===\n\n";
		cout << "I have selected a number between 1 and 100. Can you guess it?\n";

		num = guessNum[rand() % 10]; // Select a random number from the array

		while (lives > 0) {
			cout << "\nEnter your guess: ";
			cin >> guess;

			if (cin.fail()) { // Check for invalid input
				cin.clear();
				cin.ignore(10000, '\n');
				system("cls");
				cout << "\nInvalid input. Please enter a number! \n";
				continue;
			}

			if (guess == num) {
				cout << "\nCorrect! You've guessed the number:" << num << " \n";
				cout << "----------------------------------------\n";
				break;
			} 
			else {
				cout << "\nIncorrect guess! \n";
				--lives;
				cout << "Lives remaining: " << lives << ".\n";
				cout << "----------------------------------------\n";

				if (guess > num && lives > 0) { 
					cout << "Try a lower number.\n"; // If the guessed number is higher than the selected number
				}
				else if (guess < num && lives > 0) {
					cout << "Try a higher number.\n"; // If the guessed number is lower than the selected number
				}
			}

			if (lives == 0) {
				cout << "\nGame Over! You've run out of lives.\n";
				cout << "The number was: " << num << "\n";
				cout << "----------------------------------------\n";
			}
		}

		while (true) {
			cout << "\nWould you like to play again?\n";
			cout << " - Yes\n";
			cout << " - No\n";
			cout << "Your answer here: ";
			cin >> playAgain;

			string playAgainLower = playAgain; // Create a new string variable to store the lowercase version of playAgain
			for (char& c : playAgainLower) c = tolower(c); // Convert the string to lowercase

			if (playAgainLower == "yes") {
				system("cls");
				break;
			}
			else if (playAgainLower == "no") {
				system("cls");
				return 1;
			}
			else {
				cout << "\nWrong input, try again.\n";
			}
		}

	}
	cout << "Good Game! See you next time.\n";
	system("cls");
	return 1;
}

int help() { // Creates a function for the help page
	cout << "\n=== Help ===\n\n";

	cout << "This page will help you understand how to use SynoNum.\n\n";

	cout << "1. Navigating the Menu\n\n";
	cout << "- When the main menu appears, type the number of the\n";
	cout << "  option you want (1–5) and press Enter.\n";
	cout << "- Example: To start word games, type 2 and press Enter.\n\n";

	cout << "2. Entering Answers\n";
	cout << "----------------------------------------\n";
	cout << "- For the maths game, type your answer as a number.\n";
	cout << "- For the word game, type a single letter.\n";
	cout << "- Make sure you press Enter after every input.\n\n";

	cout << "3. Handling Invalid Input\n";
	cout << "----------------------------------------\n";
	cout << "- If you enter something that isn't a number when one\n";
	cout << "  is required, the program will reset the input and ask\n";
	cout << "  you again.\n";
	cout << "- If you mistype a menu number, the program will ask\n";
	cout << "  you to choose between 1 and 5.\n\n";

	cout << "4. Returning to the Menu\n";
	cout << "----------------------------------------\n";
	cout << "- After you finish a game, you will be asked if you\n";
	cout << "  want to play again.\n";
	cout << "- If you enter N, the game returns you to the main menu.\n\n";

	cout << "5. Exiting the Program\n";
	cout << "----------------------------------------\n";
	cout << "- To exit, simply choose option 5 from the main menu.\n";
	cout << "- This safely closes SynoNum.\n\n";

	cout << "If you still need help, please consult the\n";
	cout << "Read About the Games section (option 4).\n\n";

	cout << "Press any key and hit Enter to return to the main menu... ";

	string temp; // Create a temporary string variable to hold the input
	cin >> temp;

	system("cls");
	return 1; // Exit the function
}

int readAboutTheGames() { // Create a function to explain the games
	cout << "\n=== About the Games ===\n\n";

	cout << "1. Maths Games\n";
	cout << "----------------------------------------\n";
	cout << "== Maths Quiz ==\n\n";
	cout << "- Choose from four modes:\n";
	cout << " = Addition: Solve random addition problems.\n";
	cout << " = Subtraction: Solve random subtraction problems.\n";
	cout << " = Multiplication: Solve multiplication exercises.\n";
	cout << " = Division: Solve simple division problems.\n";
	cout << "- You start with 5 lives. Each incorrect answer removes one life.\n";
	cout << "- The goal is to answer as many questions correctly as possible.\n\n";
	cout << "== Guess the Number ==\n\n";
	cout << "- A random number between 1 and 100 is selected.\n";
	cout << "- You have 5 lives to guess the correct number.\n";
	cout << "- After each wrong guess, you'll be told if the number is higher or lower.\n";
	cout << "- Guess the number before you run out of lives to win!\n\n";

	cout << "2. Word Games (Hangman)\n";
	cout << "----------------------------------------\n";
	cout << "- A random word is selected, and you must guess it one letter\n";
	cout << "  at a time.\n";
	cout << "- Each wrong guess costs you a life. You have 5 lives in total.\n";
	cout << "- If you reveal all letters, you win.\n";
	cout << "- If you lose all lives, the game ends.\n\n";

	cout << "Both game modes are designed for fun and practice in a simple, friendly way!\n\n";

	cout << "Press any key and hit Enter to return to the main menu... ";

	string temp; // Create a temporary string variable to hold the input
	cin >> temp; 

	system("cls");
	return 1; // Exit the function
}

int wordList() { // Create a function for the word games list
	while (true) {
		cout << "\n=== Word Games List ===\n\n";
		cout << "1. Hangman\n";
		cout << "2. Return to Main Menu\n\n";
		cout << "Your answer here: ";

		int option = 0;
		cin >> option;

		if (cin.fail()) { // Check for invalid input
			cin.clear();
			cin.ignore(10000, '\n');
			system("cls");
			cout << "\nInvalid input. Please enter a number! \n";
			continue; 
		}

		switch (option) { // Different cases depending on the player's choice
		case 1:
			cout << endl << "Redirecting you to the hangman game ..." << endl;
			system("cls");
			hangingMan(); // Redirect to the hangman function
			break;

		case 2:
			cout << endl << "Redirecting to the main menu ..." << endl;
			system("cls");
			return 1;
			break;

		default:
			system("cls");
			cout << endl << "Please choose a valid option (1-2): \n";
			continue; // Restart the loop for invalid option
		}

		return 1;
	}
}

int mathList() { // Create a function for the maths games list
	while (true) {
		cout << "\n=== Maths Games List ===\n\n";
		cout << "1. Maths Quiz\n";
		cout << "2. Guess the Number\n";
		cout << "3. Return to Main Menu\n\n";
		cout << "Your answer here: ";

		int option = 0;
		cin >> option;

		if (cin.fail()) { // Check for invalid input
			cin.clear();
			cin.ignore(10000, '\n');
			system("cls");
			cout << "\nInvalid input. Please enter a number! \n";
			continue;
		}

		switch (option) { // Different cases depending on the player's choice
		case 1:
			cout << endl << "Redirecting you to the math quiz ..." << endl;
			system("cls");
			mathQuiz(); // Redirect to the math quiz function
			break; 

		case 2:
			cout << endl << "Redirecting you to the guess the number game ..." << endl;
			system("cls");
			guessNumber();
			break;

		case 3:
			cout << endl << "Returning to the main menu ..." << endl;
			system("cls");
			return 1; // Exit the function to return to the main menu
			break;

		default:
			system("cls");
			cout << endl << "Please choose a valid option (1-3): \n";
			continue; // Restart the loop for invalid option
		}
		return 1; 
	}
}

int main() { // Create the main function that opens when you run the programme
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

		int option = 0;
		cin >> option;

		if (cin.fail()) { // Check for invalid input
			cin.clear();
			cin.ignore(10000, '\n');
			system("cls");
			cout << "\nInvalid input. Please enter a number! \n\n";
			continue;
		}

		switch (option) { // Different cases depending on the player's choice
		case 1:
			cout << endl << "Redirecting you to the list of the maths games ..." << endl;
			system("cls");
			mathList(); // Redirect to the maths games list function
			break; 

		case 2:
			cout << endl << "Redirecting you to the list of the word games ..." << endl;
			system("cls");
			wordList(); // Redirect to the word games list function
			break;

		case 3:
			cout << endl << "Redirecting you to the help page ..." << endl;
			system("cls");
			help(); // Redirect to the help function
			break; 

		case 4:
			cout << endl << "Redirecting you to the explanation page ..." << endl;
			system("cls");
			readAboutTheGames(); // Redirect to the read about the games function
			break;

		case 5:
			cout << endl << "Shutting down the programme ... Goodbye!";
			system("cls");
			return 0; // Exit the programme

		default:
			system("cls");
			cout << endl << "Please choose a valid option (1-5): \n\n";
			break; // Restart the loop for invalid option
		}
	}
}