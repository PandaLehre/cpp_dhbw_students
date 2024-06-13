#include <iostream>

template <class playerOneType, class playerTwoType>

void Game<playerOneType, playerTwoType>::playGame()
{
   m_board.printBoard();

   while (true)
   {
      m_board = m_playerOne.makeMove(m_board);
      m_board.printBoard();
      if (m_board.isGameOver())
      {
         std::cout << "We have a winner: Player One!" << std::endl;
         break;
      }

      m_board = m_playerTwo.makeMove(m_board);
      m_board.printBoard();
      if (m_board.isGameOver())
      {
         std::cout << "We have a winner: Player Two!" << std::endl;
         break;
      }
   }
}
