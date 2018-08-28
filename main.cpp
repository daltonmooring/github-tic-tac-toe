#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <string>
#include <time.h>
#include <ctime>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Board.h"

/*
use:
bash directory
g++ -g *.cpp -o name -std=c++11
./name

*/

void user_choose_o(Board& in_board){
  int in_x,in_y,random_x,random_y,random_slot;
  std::vector<std::pair<int,int> > possible_locs;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      possible_locs.push_back(std::make_pair(i,j));
    }
  }
  while(true){
    if (in_board.O_win()){
      std::cout<<"You win! Good job"<<std::endl;
      break;
    }
    if (in_board.X_win()){
      std::cout<<"You lose :("<<std::endl;
      break;
    }
    if(in_board.full()){
      std::cout<<"Tie!"<<std::endl;
      break;
    }
    if (possible_locs.size()==9){ // if first turn computer goes first
      random_slot = rand()% possible_locs.size();
      random_x = possible_locs[random_slot].first;
      random_y = possible_locs[random_slot].second;
      in_board.AddX(random_x,random_y);
      for (std::vector<std::pair<int,int> >::iterator itr =possible_locs.begin();itr!=possible_locs.end();itr++){
        if(itr->first==random_x&&itr->second==random_y){
          possible_locs.erase(itr);
          break;
        }
      }
      std::this_thread::sleep_for (std::chrono::seconds(1));
      std::cout<<"computer's move: \n"<<in_board<<std::endl;
    }

    std::cout<<"Enter your x: ";
    std::cin>>in_x;
    if(in_x>2 || in_x <0) {
      std::cout<<"Cmon man stop trying to break the program"<<std::endl;
      continue;
    }
    std::cout<<"Enter your y: ";
    std::cin>>in_y;
    if(in_y>2 || in_y <0) {
      std::cout<<"Cmon man stop trying to break the program"<<std::endl;
      continue;
    }
    if(!in_board.clear(in_x,in_y)){
      std::cout<<"There is something currently in that location"<<std::endl;
      continue;
    }
    in_board.AddO(in_x,in_y);

    for (std::vector<std::pair<int,int> >::iterator itr =possible_locs.begin();itr!=possible_locs.end();itr++){
      if(itr->first==in_x&&itr->second==in_y){
        possible_locs.erase(itr);
        break;
      }
    }
    std::cout<<"Your move: \n"<<in_board<<std::endl;
    if (in_board.O_win()){
      std::cout<<"You win! Good job"<<std::endl;
      break;
    }
    if (in_board.X_win()){
      std::cout<<"You lose :("<<std::endl;
      break;
    }
    if(in_board.full()){
      std::cout<<"Tie!"<<std::endl;
      break;
    }

    if (possible_locs.size()!=0){ // if only possible move left
      random_slot = rand()% possible_locs.size();
      random_x = possible_locs[random_slot].first;
      random_y = possible_locs[random_slot].second;
      if (!in_board.clear(random_x,random_y)){ // if first random isnt good
        while(!in_board.clear(random_x,random_y)){ //keep getting random spots until one is good
          random_slot = rand()% possible_locs.size();
          random_x = possible_locs[random_slot].first;
          random_y = possible_locs[random_slot].second;
        }
      }
    }
    else if (possible_locs.size()==0){
      random_x = possible_locs[0].first;
      random_y = possible_locs[0].second;
    }

    in_board.AddX(random_x,random_y);
    for (std::vector<std::pair<int,int> >::iterator itr =possible_locs.begin();itr!=possible_locs.end();itr++){
      if(itr->first==random_x&&itr->second==random_y){
        possible_locs.erase(itr);
        break;
      }
    }

    std::cout<<"computer's move: \n"<<in_board<<std::endl;
  }
}

void user_choose_x(Board& in_board){
  int in_x,in_y,random_x,random_y,random_slot;
  std::vector<std::pair<int,int> > possible_locs;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      possible_locs.push_back(std::make_pair(i,j));
    }
  }
  while(true){
    if (in_board.O_win()){
      std::cout<<"You lose :("<<std::endl;
      break;
    }
    if (in_board.X_win()){
      std::cout<<"You win! Good job"<<std::endl;
      break;
    }
    if(in_board.full()){
      std::cout<<"Tie!"<<std::endl;
      break;
    }

    std::cout<<"Enter your x: ";
    std::cin>>in_x;
    if(in_x>2 || in_x <0) {
      std::cout<<"Cmon man stop trying to break the program"<<std::endl;
      continue;
    }
    std::cout<<"Enter your y: ";
    std::cin>>in_y;
    if(in_y>2 || in_y <0) {
      std::cout<<"Cmon man stop trying to break the program"<<std::endl;
      continue;
    }
    if(!in_board.clear(in_x,in_y)){
      std::cout<<"There is something currently in that location"<<std::endl;
      continue;
    }
    in_board.AddX(in_x,in_y);

    for (std::vector<std::pair<int,int> >::iterator itr =possible_locs.begin();itr!=possible_locs.end();itr++){
      if(itr->first==in_x&&itr->second==in_y){
        possible_locs.erase(itr);
        break;
      }
    }
    std::cout<<"Your move: \n"<<in_board<<std::endl;
    if (in_board.O_win()){
      std::cout<<"You lose :("<<std::endl;
      break;
    }
    if (in_board.X_win()){
      std::cout<<"You win! Good job"<<std::endl;
      break;
    }
    if(in_board.full()){
      std::cout<<"Tie!"<<std::endl;
      break;
    }
    if (possible_locs.size()!=0){
      random_slot = rand()% possible_locs.size();
      random_x = possible_locs[random_slot].first;
      random_y = possible_locs[random_slot].second;
      if (!in_board.clear(random_x,random_y)){ // if first random isnt good
        while(!in_board.clear(random_x,random_y)){ //keep getting random spots until one is good
          random_slot = rand()% possible_locs.size();
          random_x = possible_locs[random_slot].first;
          random_y = possible_locs[random_slot].second;
        }
      }
    }
    else if (possible_locs.size()==0){
      random_x = possible_locs[0].first;
      random_y = possible_locs[0].second;
    }

    in_board.AddO(random_x,random_y);
    for (std::vector<std::pair<int,int> >::iterator itr =possible_locs.begin();itr!=possible_locs.end();itr++){
      if(itr->first==random_x&&itr->second==random_y){
        possible_locs.erase(itr);
        break;
      }
    }
    std::this_thread::sleep_for (std::chrono::seconds(1));

    std::cout<<"computer's move: \n"<<in_board<<std::endl;
  }
}

int main(){
  std::cout<<"******Tic Tac Toe!******"<<std::endl;
  srand (time(NULL));
  std::string name;
  char user_xo,comp_xo;
  std::cout<<"Enter name"<<std::endl;
  std::cin>>name;
  std::cout<<"Hello "<<name<<" would you like to be x or o?"<<std::endl;
  std::cin>>user_xo;
  if(user_xo!='X' && user_xo !='O'&&user_xo!='x' && user_xo !='o'){ // invalid input
    while(true){
      std::cout<<"Wow really??? Try again"<<std::endl;
      std::cin>>user_xo;
      if(user_xo=='X' || user_xo =='O'||user_xo=='x' || user_xo =='o'){
        std::cout<<"Thank you :)"<<std::endl;
        break;
      }
    }
  }
  std::cout<<"Alright, lets get this show on the road"<<std::endl;

  if (user_xo == 'x') {
    user_xo = 'X';
  }
  if (user_xo == 'o') {
    user_xo = 'O';
  }
  Board my_board;

  if(user_xo =='X'){
    std::cout<<my_board<<std::endl;
    user_choose_x(my_board);
  }
  if(user_xo =='O') user_choose_o(my_board);

  std::string again,change;
  while(true){
    std::cout<<"Play again? (y/n)"<<std::endl;
    std::cin>>again;
    if (again=="y"||again=="Y"){
      while(true){
        std::cout<<"Would you like to change to ";
        if (user_xo=='X') std::cout<<"O? (y/n)"<<std::endl;
        if (user_xo=='O') std::cout<<"X? (y/n)"<<std::endl;
        std::cin>>change;
        if (change=="y"||change=="Y"){
          if (user_xo=='X') {
            user_xo='O';
            std::cout<<"Alright lets do it, you are now playing as O!"<<std::endl;
          }

          else if (user_xo=='O') {
            user_xo='X';
            std::cout<<"Alright lets do it, you are now playing as X!"<<std::endl;
          }
          break;
        }
        else if (change=="n"||change=="N"){
          std::cout<<"Alright lets do it!"<<std::endl;
          break;
        }
        else{
          std::cout<<"Invalid input, enter y or n."<<std::endl;
          continue;
        }
      }

      Board new_board;
      if(user_xo =='X'){
        std::cout<<new_board<<std::endl;
        user_choose_x(new_board);
      }
      if(user_xo =='O') user_choose_o(new_board);
    }
    else if (again=="n"||again=="N"){
      std::cout<<"Thank you for playing!"<<std::endl;
      break;
    }
    else{
      std::cout<<"Invalid input, enter y or n."<<std::endl;
      continue;
    }
  }

  return 0;
}
