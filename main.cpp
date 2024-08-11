/***** 3D Tic Tac Toe

          /-----------/|
         / 1 | 2 | 3 / |
        /-----------/  |
       / 4 | 5 | 6 /   |
      /-----------/    |
     / 7 | 8 | 9 /     |
    /-----------/      |
   |       |           |
   |      /-----------/|
   |     / 1 | 2 | 3 / |
   |    /-----------/  |
   |   / 4 | 5 | 6 /   |
   |  /---------- /    |
   | / 7 | 8 | 9 /     |
   |/-----------/      |
   |       |           |
   |      /-----------/
   |     / 1 | 2 | 3 /
   |    /-----------/
   |   / 4 | 5 | 6 /
   |  /-----------/
   | / 7 | 8 | 9 /
   |/-----------/


     Z
     |
     |
     |
     |
     |
     |____________X
    /
   /
  /
 /
Y

*/

#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <limits>

using namespace std;

const int8_t BOARD_SIZE = 3;

void print_board(vector<vector<vector<char>>> &board)
{
    cout << "\n";
    cout << "          /-----------/|\n";
    cout << "         / " << board[0][0][2] << " / " << board[1][0][2] << " / " << board[2][0][2] << " / |\n";
    cout << "        /-----------/  |\n";
    cout << "       / " << board[0][1][2] << " / " << board[1][1][2] << " / " << board[2][1][2] << " /   |\n";
    cout << "      /-----------/    |\n";
    cout << "     / " << board[0][2][2] << " / " << board[1][2][2] << " / " << board[2][2][2] << " /     |\n";
    cout << "    /-----------/      |\n";
    cout << "   |      |            |\n";
    cout << "   |      /-----------/|\n";
    cout << "   |     / " << board[0][0][1] << " / " << board[1][0][1] << " / " << board[2][0][1] << " / |\n";
    cout << "   |    /-----------/  |\n";
    cout << "   |   / " << board[0][1][1] << " / " << board[1][1][1] << " / " << board[2][1][1] << " /   |\n";
    cout << "   |  /-----------/    |\n";
    cout << "   | / " << board[0][2][1] << " / " << board[1][2][1] << " / " << board[2][2][1] << " /     |\n";
    cout << "   |/-----------/      |\n";
    cout << "   |      |            |\n";
    cout << "   |      /-----------/\n";
    cout << "   |     / " << board[0][0][0] << " / " << board[1][0][0] << " / " << board[2][0][0] << " /\n";
    cout << "   |    /-----------/\n";
    cout << "   |   / " << board[0][1][0] << " / " << board[1][1][0] << " / " << board[2][1][0] << " /\n";
    cout << "   |  /-----------/\n";
    cout << "   | / " << board[0][2][0] << " / " << board[1][2][0] << " / " << board[2][2][0] << " /\n";
    cout << "   |/-----------/\n";
    cout << "\n";
}

bool is_valid_move(vector<vector<vector<char>>> &board, array<int, BOARD_SIZE> &move)
{

    if (move[0] < 0 || move[0] >= BOARD_SIZE || move[1] < 0 || move[1] >= BOARD_SIZE || move[2] < 0 || move[2] >= BOARD_SIZE)
    {
        cout << "Invalid move, out of range. Try again.\n";
        return false;
    }
    else if (board[move[0]][move[1]][move[2]] != ' ')
    {
        cout << "Invalid move, there is already a symbol at this location. Try again.\n";
        return false;
    }
    else
    {
        cout << "Valid";
        return true;
    }
}

array<int, BOARD_SIZE> get_move(vector<vector<vector<char>>> &board, array<int, BOARD_SIZE> &player_move)
{
    while (true)
    {
        cout << "Enter three numbers (with a space in between) to place your move: ";
        string input;
        getline(cin, input);
        stringstream ss(input);

        if (ss >> player_move[0] >> player_move[1] >> player_move[2]) // Ensure the input is 3 numbers spaced apart
        {
            if (ss.eof() && is_valid_move(board, player_move))
            {
                return player_move;
            }
        }

        cout << "Invalid input. Please enter three integers separated by spaces.\n";
    }
}

bool check_win(vector<vector<vector<char>>> &board, char &player_character)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // Check rows
        if (board[i][0][0] == player_character && board[i][1][0] == player_character && board[i][2][0] == player_character)
        {
            return true;
        }
        else if (board[i][0][1] == player_character && board[i][1][1] == player_character && board[i][2][1] == player_character)
        {
            return true;
        }
        else if (board[i][0][2] == player_character && board[i][1][2] == player_character && board[i][2][2] == player_character)
        {
            return true;
        }

        // Check columns
        else if (board[0][i][0] == player_character && board[1][i][0] == player_character && board[2][i][0] == player_character)
        {
            return true;
        }
        else if (board[0][i][1] == player_character && board[1][i][1] == player_character && board[2][i][1] == player_character)
        {
            return true;
        }
        else if (board[0][i][2] == player_character && board[1][i][2] == player_character && board[2][i][2] == player_character)
        {
            return true;
        }

        // Check diagonals
        else if (board[0][0][i] == player_character && board[1][1][i] == player_character && board[2][2][i] == player_character)
        {
            return true;
        }
        else if (board[0][2][i] == player_character && board[1][1][i] == player_character && board[2][0][i] == player_character)
        {
            return true;
        }

        // Check verticals
        else if (board[0][i][0] == player_character && board[0][i][1] == player_character && board[0][i][2] == player_character)
        {
            return true;
        }
        else if (board[1][i][0] == player_character && board[1][i][1] == player_character && board[1][i][2] == player_character)
        {
            return true;
        }
        else if (board[2][i][0] == player_character && board[2][i][1] == player_character && board[2][i][2] == player_character)
        {
            return true;
        }

        // Check vertical diagonals
        else if (board[0][0][0] == player_character && board[1][1][1] == player_character && board[2][2][2] == player_character)
        {
            return true;
        }
        else if (board[2][2][0] == player_character && board[1][1][1] == player_character && board[0][0][2] == player_character)
        {
            return true;
        }
        else if (board[0][2][0] == player_character && board[1][1][1] == player_character && board[2][0][2] == player_character)
        {
            return true;
        }
        else if (board[2][0][0] == player_character && board[1][1][1] == player_character && board[0][2][2] == player_character)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<vector<vector<char>>> board(BOARD_SIZE, vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, ' ')));
    array<int, BOARD_SIZE> player_move;

    print_board(board);
    cout << "Example move: 0 0 0\n";

    // Game loop
    for (int i = 0; i < BOARD_SIZE ^ 3; i++)
    {
        player_move = get_move(board, player_move);
        char player_character = (i % 2 == 0) ? 'X' : 'O';
        board[player_move[0]][player_move[1]][player_move[2]] = player_character;

        print_board(board);

        if (check_win(board, player_character))
        {
            cout << "Player " << player_character << " wins!\n";
            break;
        }
    }

    return 0;
}