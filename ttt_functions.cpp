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