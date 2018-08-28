#include "Board.h"

Board::Board(){ // creates a dynamically allocated board
  char** m_data = new char*[3];
  for (int i=0;i<3;i++){
    m_data[i]= new char[3];
    for (int j=0;j<3;j++){
      m_data[i][j] = ' ';
    }
  }
  this ->m_data = m_data;
}

bool Board::clear(int x,int y){ // checks if x,y spot in board is
  if (m_data[x][y]==' ') return true;
  return false;
}

void Board::AddX(int x,int y){ // board modifier
  m_data[x][y] = 'X';
}

void Board::AddO(int x,int y){ // board modifier
  m_data[x][y] = 'O';
}

bool Board::full(){ // is the board full?
  for(int i =0;i<3;i++){
    for(int j=0;j<3;j++){
      if (m_data[i][j]==' ') { // if any spot on the board is not empty
        return false;
      }
    }
  }
  return true;
}

bool Board::X_win(){ // has X won?
  bool row0,row1,row2;
  bool col0,col1,col2;
  bool dia_left_right,dia_right_left;
  row0 = m_data[0][0]=='X' && m_data[0][1]=='X' && m_data[0][2]=='X';
  row1 = m_data[1][0]=='X' && m_data[1][1]=='X' && m_data[1][2]=='X';
  row2 = m_data[2][0]=='X' && m_data[2][1]=='X' && m_data[2][2]=='X';

  col0 = m_data[0][0]=='X' && m_data[1][0]=='X' && m_data[2][0]=='X';
  col1 = m_data[0][1]=='X' && m_data[1][1]=='X' && m_data[2][1]=='X';
  col2 = m_data[0][2]=='X' && m_data[1][2]=='X' && m_data[2][2]=='X';

  dia_left_right = m_data[0][0] == 'X' && m_data[1][1]=='X'&&m_data[2][2]=='X';
  dia_right_left = m_data[0][2] =='X' && m_data[1][1]=='X'&& m_data[2][0]=='X';

  if (row0||row1||row2||col0||col1||col2||dia_left_right||dia_right_left) return true;
  return false;
}
bool Board::O_win(){ // has O won?
  bool row0,row1,row2;
  bool col0,col1,col2;
  bool dia_left_right,dia_right_left;
  row0 = m_data[0][0]=='O' && m_data[0][1]=='O' && m_data[0][2]=='O';
  row1 = m_data[1][0]=='O' && m_data[1][1]=='O' && m_data[1][2]=='O';
  row2 = m_data[2][0]=='O' && m_data[2][1]=='O' && m_data[2][2]=='O';

  col0 = m_data[0][0]=='O' && m_data[1][0]=='O' && m_data[2][0]=='O';
  col1 = m_data[0][1]=='O' && m_data[1][1]=='O' && m_data[2][1]=='O';
  col2 = m_data[0][2]=='O' && m_data[1][2]=='O' && m_data[2][2]=='O';

  dia_left_right = m_data[0][0] == 'O' && m_data[1][1] =='O' && m_data[2][2] =='O';
  dia_right_left = m_data[0][2] == 'O' && m_data[1][1] =='O' && m_data[2][0] =='O';

  if (row0||row1||row2||col0||col1||col2||dia_left_right||dia_right_left) return true;
  return false;

}

std::ostream& operator<<(std::ostream& out, const Board in_board){
  char** data =in_board.getData();
  out<<underline_start;
  out<<data[0][0]<<"|"<<data[0][1]<<"|"<<data[0][2]<<std::endl;
  out<<underline_stop;
  out<<underline_start;
  out<<data[1][0]<<"|"<<data[1][1]<<"|"<<data[1][2]<<std::endl;
  out<<underline_stop;
  out<<data[2][0]<<"|"<<data[2][1]<<"|"<<data[2][2]<<std::endl;
}
