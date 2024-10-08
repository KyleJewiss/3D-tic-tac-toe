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

int BOARD_SIZE = 3;

// void print_board(vector<vector<vector<char>>> &board)
// {
//     cout << "\n";
//     cout << "          /-----------/|\n";
//     cout << "         / " << board[0][0][2] << " / " << board[1][0][2] << " / " << board[2][0][2] << " / |\n";
//     cout << "        /-----------/  |\n";
//     cout << "       / " << board[0][1][2] << " / " << board[1][1][2] << " / " << board[2][1][2] << " /   |\n";
//     cout << "      /-----------/    |\n";
//     cout << "     / " << board[0][2][2] << " / " << board[1][2][2] << " / " << board[2][2][2] << " /     |\n";
//     cout << "    /-----------/      |\n";
//     cout << "   |      |            |\n";
//     cout << "   |      /-----------/|\n";
//     cout << "   |     / " << board[0][0][1] << " / " << board[1][0][1] << " / " << board[2][0][1] << " / |\n";
//     cout << "   |    /-----------/  |\n";
//     cout << "   |   / " << board[0][1][1] << " / " << board[1][1][1] << " / " << board[2][1][1] << " /   |\n";
//     cout << "   |  /-----------/    |\n";
//     cout << "   | / " << board[0][2][1] << " / " << board[1][2][1] << " / " << board[2][2][1] << " /     |\n";
//     cout << "   |/-----------/      |\n";
//     cout << "   |      |            |\n";
//     cout << "   |      /-----------/\n";
//     cout << "   |     / " << board[0][0][0] << " / " << board[1][0][0] << " / " << board[2][0][0] << " /\n";
//     cout << "   |    /-----------/\n";
//     cout << "   |   / " << board[0][1][0] << " / " << board[1][1][0] << " / " << board[2][1][0] << " /\n";
//     cout << "   |  /-----------/\n";
//     cout << "   | / " << board[0][2][0] << " / " << board[1][2][0] << " / " << board[2][2][0] << " /\n";
//     cout << "   |/-----------/\n";
//     cout << "\n";
// }

void print_board(vector<vector<vector<char>>> &board)
{
    cout << "\n";
    for (int z = BOARD_SIZE - 1; z >= 0; --z)
    {
        if (z < BOARD_SIZE - 1)
        {
            cout << "   |      |            |\n";
            cout << "   |      /-----------/|\n";
        }
        for (int y = 0; y < BOARD_SIZE; ++y)
        {
            if (y == 0)
            {
                cout << "          /-----------/|\n";
            }
            else
            {
                cout << "   |    /-----------/  |\n";
            }
            cout << "   |   / ";
            for (int x = 0; x < BOARD_SIZE; ++x)
            {
                cout << board[x][y][z];
                if (x < BOARD_SIZE - 1)
                {
                    cout << " / ";
                }
                else
                {
                    cout << " /   |\n";
                }
            }
        }
        cout << "   |  /-----------/    |\n";
    }
    cout << "   |/-----------/\n";
    cout << "\n";
}

bool is_valid_move(vector<vector<vector<char>>> &board, vector<int> &move)
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
        return true;
    }
}

vector<int> get_move(vector<vector<vector<char>>> &board, vector<int> &player_move)
{
    string input;
    while (true)
    {
        cout << "Enter your move (x y z): ";
        getline(cin, input);
        stringstream ss(input);
        player_move.resize(3);
        if (ss >> player_move[0] >> player_move[1] >> player_move[2])
        {
            if (ss.eof() && is_valid_move(board, player_move))
            {
                break;
            }
        }
        cout << "Invalid input. Please enter three integers separated by spaces.\n";
    }
    return player_move;
}

bool check_verticals(vector<vector<vector<char>>> &board, char &player_character)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            bool win = true;
            for (int k = 0; k < BOARD_SIZE; k++)
            {
                if (board[i][j][k] != player_character)
                {
                    win = false;
                    break;
                }
            }
            if (win)
            {
                return true;
            }
        }
    }
    return false;
}

bool check_rows(vector<vector<vector<char>>> &board, char &player_character)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            bool win = true;
            for (int k = 0; k < BOARD_SIZE; k++)
            {
                if (board[i][k][j] != player_character)
                {
                    win = false;
                    break;
                }
            }
            if (win)
            {
                return true;
            }
        }
    }
    return false;
}

bool check_columns(vector<vector<vector<char>>> &board, char &player_character)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            bool win = true;
            for (int k = 0; k < BOARD_SIZE; k++)
            {
                if (board[k][i][j] != player_character)
                {
                    win = false;
                    break;
                }
            }
            if (win)
            {
                return true;
            }
        }
    }
    return false;
}

bool check_diagonals(vector<vector<vector<char>>> &board, char &player_character)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        bool win = true;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[j][j][i] != player_character)
            {
                win = false;
                break;
            }
            if (board[j][BOARD_SIZE - 1 - j][i] != player_character)
            {
                win = false;
                break;
            }
        }
        if (win)
        {
            return true;
        }
    }
    return false;
}

bool check_vertical_diagonals(vector<vector<vector<char>>> &board, char &player_character)
{
    bool win = true;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][i][i] != player_character)
        {
            win = false;
            break;
        }
        if (board[BOARD_SIZE - 1 - i][BOARD_SIZE - 1 - i][BOARD_SIZE - 1 - i] != player_character)
        {
            win = false;
            break;
        }
        if (board[i][BOARD_SIZE - 1 - i][i] != player_character)
        {
            win = false;
            break;
        }
        if (board[BOARD_SIZE - 1 - i][i][i] != player_character)
        {
            win = false;
            break;
        }
    }
    if (win)
    {
        return true;
    }
    return false;
}

bool check_win(vector<vector<vector<char>>> &board, char &player_character)
{
    return check_rows(board, player_character) || check_columns(board, player_character) || check_diagonals(board, player_character) || check_verticals(board, player_character) || check_vertical_diagonals(board, player_character);
}

int main()
{
    cout << "Enter board size (up to 8): ";
    cin >> BOARD_SIZE;
    if (BOARD_SIZE < 1 || BOARD_SIZE > 8)
    {
        cout << "Invalid board size. Must be between 1 and 8.\n";
        return 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    vector<vector<vector<char>>> board(BOARD_SIZE, vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, ' ')));
    vector<int> player_move;

    print_board(board);
    cout << "Example move: 0 0 0\n";

    // Game loop
    for (int i = 0; i < BOARD_SIZE ^ BOARD_SIZE; i++)
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