#pragma once

#include "player.hpp"
#include "../game_classes/board.hpp"

class HorizontalBot : public Player
{
public:
   Board makeMove(Board& board) override;
private:

};