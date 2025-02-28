#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void getPlayerName(string &player) {
    cout << "Enter your name: ";
    cin >> player;
}

int rollDie() {
    return rand() % 6 + 1; 
}

void determineWinner(const string &player, int &playerScore, int &computerScore, int &playerStreak, int &computerStreak) {
    static int prevPlayerRoll = 0, prevComputerRoll = 0;
    static int roundCounter = 0;

    int playerRoll = rollDie();
    int computerRoll = rollDie();

    cout << player << " rolled: " << playerRoll << endl;
    cout << "Computer rolled: " << computerRoll << endl;

    if (playerRoll == 6) {
        playerRoll += rollDie();
        cout << player << " gets a bonus roll!" << endl;
    }
    if (computerRoll == 6) {
        computerRoll += rollDie();
        cout << "Computer gets a bonus roll!" << endl;
    }

    if (playerRoll == 1) {
        cout << player << " loses the next turn!" << endl;
    }
    if (computerRoll == 1) {
        cout << "Computer loses the next turn!" << endl;
    }

    if (playerRoll == prevPlayerRoll) {
        playerScore++;
        cout << player << " rolled the same number twice and gains an extra point!" << endl;
    }
    if (computerRoll == prevComputerRoll) {
        computerScore++;
        cout << "Computer rolled the same number twice and gains an extra point!" << endl;
    }

    prevPlayerRoll = playerRoll;
    prevComputerRoll = computerRoll;

    if (playerRoll > computerRoll) {
        playerScore++;
        playerStreak++;
        computerStreak = 0;
        cout << player << " wins this round!" << endl;
    } else if (computerRoll > playerRoll) {
        computerScore++;
        computerStreak++;
        playerStreak = 0;
        cout << "Computer wins this round!" << endl;
    } else {
        cout << "It's a tie this round!" << endl;
    }
 
    roundCounter++;
    if (roundCounter % 3 == 0) {
        cout << "Special Challenge Round!" << endl;
        int guess, actualRoll;
        cout << "Guess your roll (1 - 6): ";
        cin >> guess;
        actualRoll = rollDie();
        cout << "Actual roll: " << actualRoll << endl;
        if (guess == actualRoll) {
            playerScore++;
            cout << player << " guessed correctly and earns an extra point!" << endl;
        }
    }

    cout << "Current score: " << player << ": " << playerScore << " - Computer: " << computerScore << endl;
}

void displayOverallWinner(const string &player, int playerScore, int computerScore) {
    cout << "Final score: " << player << ": " << playerScore << " - Computer: " << computerScore << endl;
    if (playerScore > computerScore) {
        cout << player << " is the overall winner!" << endl;
    } else if (computerScore > playerScore) {
        cout << "Computer is the overall winner!" << endl;
    } else {
        cout << "It's a tie overall!" << endl;
    }
}

int main() {
    srand(time(0));

    string player;
    char playAgain;

    do {
        int playerScore = 0, computerScore = 0, playerStreak = 0, computerStreak = 0, rollLimit = 10, gameMode, roundCount = 0;

        getPlayerName(player);

        cout << "Select Game Mode:" << endl;
        cout << "1. Survival Mode (First to 10 points wins)" << endl;
        cout << "2. Time Attack (Limited rolls, highest score wins)" << endl;
        cout << "3. Knockout Mode (Win 3 rounds in a row to win)" << endl;
        cout << "4. Exit the game." << endl;
        cout << "Enter choice: ";
        cin >> gameMode;

        if (gameMode == 4) {
            cout << "Exiting the game. Goodbye!" << endl;
            return 0;
        }

        if (gameMode == 2) {
            cout << "Enter the number of rounds for Time Attack Mode: ";
            cin >> rollLimit;
        }

        do {
            determineWinner(player, playerScore, computerScore, playerStreak, computerStreak);
            roundCount++;

            if ((gameMode == 1 && (playerScore >= 10 || computerScore >= 10)) || 
                (gameMode == 2 && roundCount >= rollLimit) || 
                (gameMode == 3 && (playerStreak == 3 || computerStreak == 3))) {
                break;
            }
        } while (true);

        displayOverallWinner(player, playerScore, computerScore);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing! Goodbye!" << endl;
    return 0;
}