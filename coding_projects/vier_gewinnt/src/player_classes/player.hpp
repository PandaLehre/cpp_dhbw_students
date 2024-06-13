#pragma once

#include "../utility/parameter.hpp"
#include "../game_classes/board.hpp"

class Player
{
public:
   virtual ~Player()
   {};

   virtual Board makeMove(Board& board) = 0;

private:
};