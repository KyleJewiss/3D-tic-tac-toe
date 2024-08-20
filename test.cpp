#include <iostream>
#include <vector>
#include <sstream>

class TicTacToe3D {
public:
    TicTacToe3D(int size) : BOARD_SIZE(size), board(size, std::vector<std::vector<char>>(size, std::vector<char>(size, ' '))) {}

    void print_board() {
        std::string board_string;
        append_top_layer(board_string);
        append_gap_row(board_string);
        for (int i = 0; i < BOARD_SIZE - 2; i++) {
            append_middle_layer(board_string);
            append_gap_row(board_string);
        }
        append_bottom_layer(board_string);
        std::cout << board_string;
    }

private:
    int BOARD_SIZE;
    std::vector<std::vector<std::vector<char>>> board;

    void append_spaces(std::string &board_string, int count) {
        board_string.append(count, ' ');
    }

    void append_spaces_inverse(std::string &board_string, int count) {
        board_string.append((2 * BOARD_SIZE + 1) - count, ' ');
    }

    void append_polls(std::string &board_string, int index) {
        board_string.append("|");
        for (int i = 0; i < (2 * BOARD_SIZE) - index; i++) {
            board_string.append(" ");
        }
    }

    void append_polls_inverse(std::string &board_string, int index) {
        for (int i = 0; i < index; i++) {
            board_string.append(" ");
        }
        board_string.append("|");
    }

    void append_dotted_row(std::string &board_string, bool new_line = true) {
        std::string layer_left = "/----";
        std::string layer_middle = "----";
        std::string layer_right = "---/";

        board_string.append(layer_left);
        for (int i = 0; i < BOARD_SIZE - 2; i++)
            board_string.append(layer_middle);
        board_string.append(layer_right);

        if (new_line)
            board_string.append("\n");
    }

    void append_character_row(std::string &board_string, int layer, bool new_line = true) {
        std::string slash = "/";
        board_string.append(slash);
        for (int i = 0; i < BOARD_SIZE; i++) {
            std::string character = " ";
            character += board[i][layer][BOARD_SIZE - 1 - layer];
            character += " ";
            board_string.append(character);
            board_string.append(slash);
        }

        if (new_line)
            board_string.append("\n");
    }

    void append_gap_row(std::string &board_string) {
        board_string.append("|");
        for (int i = 0; i < 2 * BOARD_SIZE; i++) {
            board_string.append(" ");
        }
        board_string.append("|");
        for (int i = 0; i < 4 * BOARD_SIZE - 1; i++) {
            board_string.append(" ");
        }
        board_string.append(" ");
        board_string.append("|\n");
    }

    void append_top_layer(std::string &board_string) {
        for (int i = 0; i < 2 * BOARD_SIZE; ++i) {
            append_spaces_inverse(board_string, i);
            append_dotted_row(board_string, false);
            append_polls_inverse(board_string, i);
            board_string.append("\n");
            int j = i + 1;
            append_spaces_inverse(board_string, j);
            append_character_row(board_string, BOARD_SIZE - 1, false);
            append_polls_inverse(board_string, j);
            board_string.append("\n");
            i++;
        }
        board_string.append(" ");
        append_dotted_row(board_string, false);
        append_polls_inverse(board_string, 2 * BOARD_SIZE);
        board_string.append("\n");
    }

    void append_middle_layer(std::string &board_string) {
        for (int i = 0; i < 2 * BOARD_SIZE; ++i) {
            append_polls(board_string, i);
            append_dotted_row(board_string, false);
            append_polls_inverse(board_string, i);
            board_string.append("\n");
            int j = i + 1;
            append_polls(board_string, j);
            append_character_row(board_string, BOARD_SIZE / 2, false);
            append_polls_inverse(board_string, j);
            board_string.append("\n");
            i++;
        }
        board_string.append("|");
        append_dotted_row(board_string, false);
        append_polls_inverse(board_string, 2 * BOARD_SIZE);
        board_string.append("\n");
    }

    void append_bottom_layer(std::string &board_string) {
        for (int i = 0; i < 2 * BOARD_SIZE; ++i) {
            append_polls(board_string, i);
            append_dotted_row(board_string, true);
            int j = i + 1;
            append_polls(board_string, j);
            append_character_row(board_string, 0, true);
            i++;
        }
        append_polls(board_string, 2 * BOARD_SIZE);
        append_dotted_row(board_string, true);
    }
};

int main() {
    TicTacToe3D game(4);
    game.print_board();
}