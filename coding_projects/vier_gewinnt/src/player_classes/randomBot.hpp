#pragma once

#include "player.hpp"
#include "../game_classes/board.hpp"
#include "../utility/parameter.hpp"

class RandomBot : public Player
{
public:
   Board makeMove(Board& board) override;

private:
   int generateRandomColumnIdx() const;
};