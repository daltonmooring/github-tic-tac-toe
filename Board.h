#include <iostream>
#define underline_start "\033[4m"
#define underline_stop  "\033[0m";

#ifndef __Board_h__
#define __Board_h__
class Board{
public:
  Board(); // constructor
  bool clear(int x,int y); // checks if x,y spot in board is clear
  void AddO(int x,int y); // board modifier
  void AddX(int x,int y); // board modifier
  char** getData() const { return m_data; }
  bool full();
  bool X_win(); // keeps track of who won
  bool O_win(); // keeps track of who won

private:
  char** m_data; // internal representation of board
};

std::ostream& operator<<(std::ostream& out, const Board in_board);

#endif
