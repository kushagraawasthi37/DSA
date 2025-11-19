#include <iostream>
using namespace std;

int main()
{
    int N = 15;      // starting number
    int player = +1; // +1 = Player 1, -1 = Player 2
    int number = N;

    while (number != 0)
    {
        cout << "------------------------\n";
        cout << "Player: " << (player == 1 ? "Player 1" : "Player 2") << "\n";
        cout << "Current number: " << number << "\n";
        cout << "Choose action (- or /): ";

        char action;
        cin >> action;

        if (action == '-')
        {
            number = number - 1;
        }
        else if (action == '/')
        {
            number = number / 2;
        }
        else
        {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        player = -player; // switch player
    }

    cout << "\nGame Over!\n";
    cout << "Winner: ";
    if (player == -1)
        cout << "Player 1\n"; // because player flipped after last move
    else
        cout << "Player 2\n";

    return 0;
}
