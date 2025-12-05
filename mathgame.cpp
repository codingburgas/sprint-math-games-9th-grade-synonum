#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    srand(0);

    int score = 0;
    int numQuestions = 5;

    cout << "Welcome to the Math Game!" << endl;
    cout << "You will be asked " << numQuestions << " addition questions." << endl;

    for (int i = 0; i < numQuestions; i++) {
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 1;

        int answer;
        cout << "Question " << i + 1 << ": " << a << " + " << b << " = ";
        cin >> answer;

        if (answer == a + b) {
            cout << "Correct!" << endl;
            score++;
        }
        else {
            cout << "Wrong! The correct answer is " << a + b << "." << endl;
        }
    }

    cout << "Game over! Your score: " << score << "/" << numQuestions << endl;
}
