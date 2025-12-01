#include <iostream>
#include <string>
using namespace std;

int main() {
    srand(time(0));

    string secretWords[100] = {
        "apple",
        "mirror",
        "lantern",
        "river",
        "breeze",
        "carpet",
        "galaxy",
        "thunder",
        "crystal",
        "meadow",
        "shadow",
        "ember",
        "horizon",
        "puzzle",
        "shelter",
        "compass",
        "fabric",
        "memory",
        "harbor",
        "whisper",
        "canyon",
        "blossom",
        "canyon",
        "summit",
        "marble",
        "echo",
        "timber",
        "velvet",
        "orbit",
        "anchor",
        "lantern",
        "coral",
        "breeze",
        "vessel",
        "nectar",
        "prism",
        "canyon",
        "quill",
        "parchment",
        "ripple",
        "forest",
        "canyon",
        "glimmer",
        "tapestry",
        "relic",
        "anchor",
        "ember",
        "blossom",
        "dune",
        "current",
        "cedar",
        "stream",
        "petal",
        "cavern",
        "starlight",
        "orchard",
        "lantern",
        "cradle",
        "summit",
        "willow",
        "orbit",
        "crystal",
        "whisper",
        "moss",
        "lantern",
        "driftwood",
        "canyon",
        "terrace",
        "wander",
        "silo",
        "harvest",
        "forge",
        "shimmer",
        "meadow",
        "dusk",
        "compass",
        "ripple",
        "cedar",
        "lantern",
        "bloom",
        "ash",
        "stone",
        "timber",
        "gully",
        "plume",
        "flourish",
        "moss",
        "grain",
        "vessel",
        "pocket",
        "lantern",
        "cavern",
        "harbor",
        "spark",
        "thread",
        "summit",
        "grove",
        "quartz",
        "horizon",
        "ember"
    };
    string answer = secretWords[rand() % 100];
    string guessedWord(answer.length(), '_');
    int lives = 5;
    char guess;

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
            cout << "Wrong letter!" << endl;
        }
    }  

    

    if (guessedWord == answer) {
        cout << "You guessed the word: " << answer << endl;
    }
    else {
        cout << "You lost! The word was: " << answer << endl;
    }
}
    