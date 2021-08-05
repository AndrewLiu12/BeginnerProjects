// LetterRace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand(time(0)); // Sets the seed to the value given
    const int size = 100;
    cout << "Enter a letter to begin \n ";
    char x; cin >> x;
    int position = size / 2;
    while (true) {
        cout << "|START|";
        for (int i = 0; i < size; i++) {
            if (i == position)
                cout << x;
            else cout << " ";
        }
        cout << "|FINISH|" << endl;
        int move = rand() % 3 - 1;
        position = position + move;
        if (position < 1) { cout << "You could not finish the race!" << endl; break; }
        if (position > size - 1) { cout << "Yay! You finished the race" << endl; break; }
        for (int sleep = 0; sleep < 1000000; sleep++);
    }
    return 0;
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
