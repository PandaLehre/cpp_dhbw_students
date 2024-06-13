#pragma once

#include "../utility/playerType.hpp"
#include "../game_classes/board.hpp"
#include "../player_classes/player.hpp"


template <class playerOneType, class playerTwoType>
class Game
{
public:
   void playGame();

private:
   Board m_board;
   playerOneType m_playerOne;
   playerTwoType m_playerTwo;
};

#include "game.inl"