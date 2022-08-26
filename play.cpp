// function definitions for ttt.cpp main file

#include <iostream>
#include <vector>

std::string input[9] = {" "," "," "," "," "," "," "," "," "};
int player = 1;
int position =0;

void introduction() {

  std::cout << "Press [Enter] to begin: ";
  std::cin.ignore();

  std::cout << "\n";

  std::cout << "===========\n";
  std::cout << "Tic-Tac-Toe\n";
  std::cout << "===========\n\n";
  
  std::cout << "Player 1) ✖\n";
  std::cout << "Player 2) ⊙\n\n";

  std::cout << "Here's the 3 x 3 grid:\n\n";

  std::cout << "     |     |      \n";
  std::cout << "  1  |  2  |  3   \n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  4  |  5  |  6   \n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  7  |  8  |  9   \n";
  std::cout << "     |     |      \n\n";

}

bool is_winner() {
  bool winner = false;
  // 8 possible ways to determine winner

  //check rows 
  if(input[0] == input[1] && input[1] == input[2] && input[0] != " ") {
    winner = true; 
  }
  else if (input[3] == input[4] && input[4] == input[5] && input[3] != " ") {
    winner = true;
  }
  else if(input[6] == input[7] && input[7] == input[8] && input[6] != " ") {
    winner = true;
  }
  // check columns
  else if(input[0] == input[3] && input[3] == input[6] && input[0] != " ") {
    winner = true;
  }
  else if(input[1] == input[4] && input[4] == input[7] && input[1] != " ") {
    winner = true;
  }
  else if(input[2] == input[5] && input[5] == input[8] && input[2] != " ") {
    winner = true;
  }
  // check for diagonals
  else if(input[2] == input[4] && input[4] == input[6] && input[2] != " ") {
    winner = true;
  }
  else if(input[8] == input[4] && input[4] == input[0] && input[8] != " ") {
    winner = true;
  }
  return winner;
}

bool is_filled() {
  bool filled_up = true;

  for(int i=0; i <= 9; i++) {
    if(input[i] == " ") {
      filled_up = false;
    }
  }
  return filled_up;
}

void set_position() {
  std::cout << "player " << player << "'s turn [Enter a number between 1 - 9]:  "; 

  while (!(std::cin >> position)) {
    std::cout << "Player " << player << ", please enter a valid number between 1 and 9: ";
    std::cin.clear();
    std::cin.ignore();
  }
std::cout << "\n";

while(input[position-1] != " ") {
  std::cout << "That position is occupied try another position \n";
  std::cout << "Player " << player << "'s Turn (Enter 1-9): ";
  std::cin >> position;
  std::cout << "\n";
  }
}

void update_board() { //based on position number determine whether its player 1 or 2
  if(player % 2 == 1) {
    input[position-1] = "X";
  }
  else {
    input[position-1] = "O"; 
  }
}

void change_player() {
  if(player == 1) {
    player ++;
  }
  else {
    player--;
  }
}

void draw() {

  std::cout << "     |     |      \n";

  std::cout << "  " << input[0] << "  |  " << input[1] << "  |  " << input[2] << "\n";

  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";

  std::cout << "  " << input[3] << "  |  " << input[4] << "  |  " << input[5] << "\n";

  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";

  std::cout << "  " << input[6] << "  |  " << input[7] << "  |  " << input[8] << "\n";
  std::cout << "     |     |      \n";

  std::cout << "\n";
    
}


void take_turn() {
  while( !is_winner() && !is_filled() ) {

    set_position();

    update_board();

    change_player();
    
    draw();
  }
}

void end_game() {

  if (is_winner()) {
    std::cout << "There's a winner!\n";
  }
  else if (is_filled()) {
    std::cout << "There's a tie!\n";
  }

}




