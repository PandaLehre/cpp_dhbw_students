#include "horizontalBot.hpp"
#include "../utility/parameter.hpp"


Board HorizontalBot::makeMove(Board& board)
{   
   std::array<std::array<char, Parameter::width>, Parameter::height> boardState = board.returnBoard();

   int lowestColumnIdx = -1;
   int lowestColumnHeight = Parameter::height;

   for (int j=0; j<Parameter::width; j++)
   {
      int currentColumnHeight = Parameter::height;
      for (int i=0; i<Parameter::height; i++)
      {
         if (boardState[i][j] == Parameter::emptyCell)
         {
            currentColumnHeight--;
         }
         else
         {
            break;
         }
      }
      if (currentColumnHeight < lowestColumnHeight)
      {
         lowestColumnHeight = currentColumnHeight;
         lowestColumnIdx = j;
      }
   }

   board.placeStone(lowestColumnIdx);
   return board;
}