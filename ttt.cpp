#include <iostream>
#include <cstring>
#include "ttt.hpp"

using namespace std;

int main()
{

bool names = true;

bool game;

// Player input
int cell;


// Player points & names
int x_points = 0;
int o_points = 0;

// The turns of the game (total 9 turns)
int turn;

string player_x;
string player_o;

welcome();

do {
    cout << "player X, write your name: \n";
    getline(cin, player_x);

    cout << "player O, write your name: \n";
    getline(cin, player_o);

} while (player_x == "" || player_o == "");

while(true)
{
turn = 1;

// Player turn
char current_player = 'X';

// Reset the board
char board[] = {'1','2','3','4','5','6','7','8','9'};

// Player choice the play or not
char play;

cout << "\nStart the game? (press 'y' to play, any else to quit)\n";
cin >> play;

play = toupper(play);

if (play == 'Y')
{
    game = true;
}
else
{
    return 0;
}

bool single_game = true;

    while (single_game)
    {
    show_board(board);


    // Input from the current player
    cout << "\nPlayer " << current_player << ". Choose a cell by entering a number (1-9): \n";
    cin >> cell;


    // Convert input to 0-based index
    cell--;


    // Check is a chosen cell empty
    if (board[cell] == 'X' || board[cell] == 'O')
    {
        cout << "The cell is already taken. Choose another one!\n";
        continue;
    }


    // Update the board
    board[cell] = current_player;


    // Win check
    if (check_win(board, current_player, x_points, o_points))
    {
        show_board(board);
        cout << endl;
        cout << "Player " << current_player << " Won!\n";
        cout << endl;

        single_game = false;
    }

    // Tie check
    if (turn == 9)
    {
        cout << endl;
        cout << "The game is tie!\n";
        
        single_game = false;
    }

    // Switch player
    if (current_player == 'X')
    {
        current_player = 'O';
    }
    else if (current_player == 'O')
    {
        current_player = 'X';
    }

        turn++;
    }

    cout << "Player X: " << player_x << " points: " << x_points;
    cout << "\t\tPlayer O: " << player_o << " points: " << o_points << "\n";
    cout << endl;
}

cout << "Thank you for playing!\n";
cout << endl;

return 0;

}
