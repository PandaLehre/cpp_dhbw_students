#include <iostream>
#include <string>

#include "GameManager.hpp"

#include "../utility/playerType.hpp"
#include "../player_classes/player.hpp"
#include "../player_classes/human.hpp"
#include "../player_classes/horizontalBot.hpp"
#include "../player_classes/randomBot.hpp"

namespace HF // create namespace for helper functions
{

   PlayerType getPlayerType(std::string playerName)
   {
      std::cout << "--- \tWho should be playing " << playerName << "?" << std::endl;
      std::cout << "--- \t0: Human" << std::endl;
      std::cout << "--- \t1: Horizontal Bot" << std::endl;
      std::cout << "--- \t2: Random Bot" << std::endl;
      int inValue;
      std::cin >> inValue;
      PlayerType playerType = static_cast<PlayerType>(inValue);
      return playerType;
   }

   template <class playerOneType>
   void startGameFixedPlayerOne(PlayerType playerTwoType)
   {
      if (playerTwoType == PlayerType::human)
      {
         Game<playerOneType, Human> game;
         game.playGame();
      }
      else if (playerTwoType == PlayerType::horizontalBot)
      {
         Game<playerOneType, HorizontalBot> game;
         game.playGame();
      }
      else if (playerTwoType == PlayerType::randomBot)
      {
         Game<playerOneType, RandomBot> game;
         game.playGame();
      }
   }

} // end namespace HF

void GameManager::startGame()
{
   std::cout << "============= Welcome to Connect-4 =============" << std::endl;
   PlayerType playerOneType = HF::getPlayerType("PlayerOne");
   PlayerType playerTwoType = HF::getPlayerType("PlayerTwo");

   if (playerOneType == PlayerType::human)
   {
      HF::startGameFixedPlayerOne<Human>(playerTwoType);
   }
   else if (playerOneType == PlayerType::horizontalBot)
   {
      HF::startGameFixedPlayerOne<HorizontalBot>(playerTwoType);
   }
   else if (playerOneType == PlayerType::randomBot)
   {
      HF::startGameFixedPlayerOne<RandomBot>(playerTwoType);
   }
}
