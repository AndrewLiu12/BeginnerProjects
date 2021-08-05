// NumberGuessingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Include functions that are used, not neccesary, just a convention thing
void rules();

int main()
{
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice; // stores the random number
    char choice;
    srand(time(0)); // Sets the seed of the rng
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
    do {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";
        // Get player's betting balance
        do {
            cout << "Hey, " << playerName << ", enter amount to bet : $";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n" << "\nRe-enter balance\n ";
        } while (bettingAmount > balance);

        // Get player's numbers
        do {
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                << "Re-enter number:\n ";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1;
        if (dice == guess) {
            cout << "\n\nYou are in luck!! You have won $" << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else {
            cout << "Oops, better luck next time !! You lost $ " << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice << "\n";
        cout << "\n" << playerName << ", You have balance of $ " << balance << "\n";
    
        if (balance == 0) {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}

void rules() {
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
