#pragma once

#include <array>

#include "../utility/parameter.hpp"

class Board
{
public:
   Board();

   void printBoard() const;
   bool isGameOver() const;
   bool placeStone(const int column);
   std::array<std::array<char, Parameter::width>, Parameter::height> returnBoard() const;

private:
   std::array<std::array<char, Parameter::width>, Parameter::height> m_board;
   char m_currentPlayerIcon{Parameter::iconTwo};
};