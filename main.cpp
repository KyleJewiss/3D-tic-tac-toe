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
vector<vector<vector<char>>> board(BOARD_SIZE, vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, ' ')));
array<int, BOARD_SIZE> player_move;

void print_board()
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

bool is_valid_move(array<int, BOARD_SIZE> &move)
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

array<int, BOARD_SIZE> get_move()
{
    while (true)
    {
        cout << "Enter three numbers (with a space in between) to place your move: ";
        string input;
        getline(cin, input);
        stringstream ss(input);

        if (ss >> player_move[0] >> player_move[1] >> player_move[2]) // Ensure the input is 3 numbers spaced apart
        {
            if (ss.eof() && is_valid_move(player_move))
            {
                return player_move;
            }
        }

        cout << "Invalid input. Please enter three integers separated by spaces.\n";
    }
}

int main()
{
    print_board();
    cout << "Example move: 0 0 0\n";
    // Game loop
    for (int i = 0; i < BOARD_SIZE ^ 3; i++)
    {
        player_move = get_move();

        char player_character = (i % 2 == 0) ? 'X' : 'O';

        board[player_move[0]][player_move[1]][player_move[2]] = player_character;

        print_board();
    }

    return 0;
}