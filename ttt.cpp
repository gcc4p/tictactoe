#include <iostream>
#include "ttt.hpp"

int main() {

  bool end = false;
  char board[9];
  for(int i = 0; i < sizeof(board); i++) {
    board[i] = ' ';
  }

  greet();
  display_board(board);

  int turn = 0;
  int choice;
  while(!end) {
    if(turn % 2 == 0) {
      std::cout << "It's Player1's turn.\n";
      display_board(board);
      std::cout << "Player1, enter your choice: ";
      std::cin >> choice;
      bool valid = check_validity(choice, board);
      if (valid) {
        board[choice] = 'X';
        end = win(choice, board);
        if (end) {
          std::cout << "Player1 has won!\n";
          return 0;
        } else { 
          turn++;
        }
      }
    } else {
      std::cout << "It's Player2's turn.\n";
      display_board(board);
      std::cout << "Player2, enter your choice: ";
      std::cin >> choice;  
      bool valid = check_validity(choice, board);
      if (valid) {
        board[choice] = 'O';  
        end = win(choice, board);
        if (end) {
          std::cout << "Player2 has won!\n";
          return 0;
        } else {
          turn++;
        }
      }
    }
  }

  return 0;
}
