#include <iostream>
#include <vector>
void display_board(char board[9]) {
  std::cout << "     |     |      \n";

  std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";

  std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";

  std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  std::cout << "     |     |      \n";

  std::cout << "\n";
}

void greet() {
  std::cout << "Welcome to Tic-Tac-Toe! Player1 plays X and Player2 plays O. The board options are set up as follows: \n";
  std::cout << "\n0  1  2\n" << "\n3  4  5\n" << "\n6  7  8\n" << "\n Please enter numbers accordingly when prompted to do so.\n";
  std::cout << "Player1 starts per Tic-Tac-Toe rules.\n";
}

bool check_validity(int choice, char board[9]) {
  if(board[choice] != ' ') {
    std::cout << "Invalid input, try again!\n";
    return false;
  }
}

bool win(int choice, char board[9]) {
    // win in rows
    int row = choice / 3;
    if (board[row * 3] == board[row * 3 + 1] && board[row * 3 + 1] == board[row * 3 + 2] && board[row * 3] != ' ')
        return true;

    // win in columns
    int col = choice % 3;
    if (board[col] == board[col + 3] && board[col + 3] == board[col + 6] && board[col] != ' ')
        return true;

    // win in diagonals
    if ((choice % 2 == 0) && ((board[0] == board[4] && board[4] == board[8] && board[0] != ' ') || (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')))
        return true;

    return false;
}
