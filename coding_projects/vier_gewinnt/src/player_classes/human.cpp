#include <iostream>
#include "human.hpp"

using namespace std;

Board Human::makeMove(Board& board)
{
   bool moveWasLegal = false;
   while (!moveWasLegal)
   {
      cout << "In which column would you like to place your chip (starting with 1)?" << endl;
      int columnNum;
      cin >> columnNum;
      moveWasLegal = board.placeStone(columnNum - 1);
   }

   return board;
}