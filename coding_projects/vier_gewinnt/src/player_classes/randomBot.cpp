#include <random>

#include "randomBot.hpp"
#include "../utility/parameter.hpp"


Board RandomBot::makeMove(Board& board)
{
   bool moveWasLegal = false;
   while (!moveWasLegal)
   {
      int columnNum = generateRandomColumnIdx();
      moveWasLegal = board.placeStone(columnNum - 1);
   }

   return board;
}


int RandomBot::generateRandomColumnIdx() const
{
   std::random_device device;
   std::mt19937 generator(device());
   std::uniform_int_distribution<int> distribution(0, Parameter::width);
   return distribution(generator);
}