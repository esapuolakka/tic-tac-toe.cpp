# tic_tac_toe

Tic Tac Toe - game.




// ttt.cpp


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

// The turns of the game (total 9 turns)
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





// ttt.hpp



void welcome();
void show_board(char board[]);
bool check_win(char board[], char player);





// ttt_functions.cpp

#include <iostream>

using namespace std;


void welcome()
{
    cout << endl;
    cout << "============================\n";
    cout << "======TIC TAC TOE Game======\n";
    cout << "============================\n";
    cout << endl;
}

void show_board(char board[])
{
    cout << board[0] << "|" <<board[1] << "|" << board[2] << endl;
    cout << board[3] << "|" <<board[4] << "|" << board[5] << endl;
    cout << board[6] << "|" <<board[7] << "|" << board[8] << endl;
}

bool check_win(char board[], char player)
{
    // vertical check
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == player && board[i+3] == player && board[i+6] == player)
        {
            return true;
        }
    }
    // horizontal check
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == player && board[i+1] == player && board [i+2] == player)
        {
            return true;
        }
    }
    // diagonal check
    for (int i = 0; i < 9; i++)
    {
        if (board[0] == player && board[4] == player && board[8] == player)
        {
            return true;
        }
        else if (board[2] == player && board[4] == player && board[6] == player)
        {
            return true;
        }
    }
    return false;
}
