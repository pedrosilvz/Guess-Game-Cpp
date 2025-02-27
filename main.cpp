#include <iostream>
#include <cstdlib>      // rand()
#include <ctime>        // time()
using namespace std;

int main () {
    cout << "==================================" << endl;
    cout << "=            GUESS GAME          =" << endl;
    cout << "==================================" << endl << endl;

        
    cout << "Choose the difficulty level: " << endl;
    cout << "EASY (1), MEDIUM (2), HARD (3)" << endl;

    char difficulty;
    cin >> difficulty;

    int max_attempts;

    if (difficulty == '1') {
        max_attempts = 15;
    } else if (difficulty == '2') {
        max_attempts = 10;
    } else {
        max_attempts = 5;
    }

    srand(time(NULL));      // seed para o rand()
    const int SECRET_NUMBER = rand() % 100;

    bool not_guessed = true;

    int attempts = 0;

    double points = 1000.0;

    
    for (attempts = 1; attempts <= max_attempts; attempts++) {
        int guess;
        cout << endl;
        cout << "What's the secret number? ";
        cin >> guess;                               // input do usuário

        double last_points = abs(guess - SECRET_NUMBER)/2.0;        // abs = valor absoluto
        points = points - last_points;

        bool guessed = guess == SECRET_NUMBER;
        bool higher = guess > SECRET_NUMBER;
       
        if (guessed) {
            cout << endl;
            cout << "==========================================================" << endl << endl;
            cout << "Congrats!! You guessed the secret number with " << attempts << " attempt(s)!" << endl;
            cout << endl;
            cout << "==========================================================" << endl;
            cout << endl;
            
            not_guessed = false;
            break;
    
        } else if (higher) {
            cout << "===========================================================" << endl;
            cout << " - Your guess was higher than the secret number! Try again!" << endl;
            cout << " - Your Attempts: " << attempts << endl;
            cout << "===========================================================" << endl << endl;
    
        } else {
            cout << "=========================================================" << endl;
            cout << " - Your guess was less than the secret number! Try again!" << endl;
            cout << " - Your attempts: " << attempts << endl;
            cout << "=========================================================" << endl;
      }
    }
    cout << "End of the game!!" << endl;
    if (not_guessed) {
        cout << "You lost! Try again!" << endl;
    } else {
        cout.precision(2);                        // precisão de 2 casas decimais
        cout << fixed;                            // fixa a precisão
        cout << "Total points: " << points << " points." << endl;
    }

}
    