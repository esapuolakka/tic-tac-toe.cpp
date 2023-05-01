#include <iostream>

using namespace std;


void welcome()
{
    cout << endl;
    cout << "============================\n";
    cout << "===== TIC TAC TOE Game =====\n";
    cout << "============================\n";
    cout << endl;
}


void show_board(char board[])
{
    cout << board[0] << "|" <<board[1] << "|" << board[2] << endl;
    cout << board[3] << "|" <<board[4] << "|" << board[5] << endl;
    cout << board[6] << "|" <<board[7] << "|" << board[8] << endl;
}


bool check_win(char board[], char current_player, int& x_points, int& o_points)
{
    // vertical check
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == current_player && board[i+3] == current_player && board[i+6] == current_player)
        {
            if (current_player == 'X')
            {
                x_points++;
            }
            else
            {
                o_points++;
            }
            return true;
            
        }
    }
    // horizontal check
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == current_player && board[i+1] == current_player && board [i+2] == current_player)
        {
            if (current_player == 'X')
            {
                x_points++;
            }
            else
            {
                o_points++;
            }
            return true;
        }
    }
    // diagonal check
    for (int i = 0; i < 9; i++)
    {
        if (board[0] == current_player && board[4] == current_player && board[8] == current_player)
        {
            if (current_player == 'X')
            {
                x_points++;
            }
            else
            {
                o_points++;
            }
            return true;
        }
        else if (board[2] == current_player && board[4] == current_player && board[6] == current_player)
        {
            if (current_player == 'X')
            {
                x_points++;
            }
            else
            {
                o_points++;
            }
            return true;
        }
    }
    return false;
}