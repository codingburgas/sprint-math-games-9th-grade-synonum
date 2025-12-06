#include <iostream>
#include <string>
using namespace std;

int main() {

	bool validChoice = false;

	while (validChoice == false) {

		int choice = 0;

		cout << "Choose a number corresponding to the game mode you want to play: \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division";
		cin >> choice;

		if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
			cout << "Invalid choice. Please select a valid game mode.\n";
		}
		else {
			validChoice = true;
			cout << "You have selected game mode " << choice << ". - Starting game...\n";
		}
	}
}