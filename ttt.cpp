#include <iostream>
#include "ttt.hpp"

using namespace std;

int main()
{

char board[] = {'1','2','3','4','5','6','7','8','9'};

bool game_on = true;
// Player input
int cell;

// Player turn
char player = 'X';

// The turns of the game (total 9)
int turn = 1;

welcome();

while (game_on)
{

show_board(board);


// Input from the current player
cout << "\nChoose your cell " << player << " enter a number (1-9): \n";
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
board[cell] = player;


// Win check
if (check_win(board, player))
{
    show_board(board);
    cout << endl;
    cout << "Player " << player << " Won!\n";
    cout << endl;
    game_on = false;
}

// Tie check
if (turn == 9)
{
    cout << endl;
    cout << "The game is tie!\n";
    game_on = false;
}

// Switch player
if (player == 'X')
{
    player = 'O';
}
else if (player == 'O')
{
    player = 'X';
}

turn++;

}

cout << "Thank you for playing!\n";
cout << endl;

return 0;

}
