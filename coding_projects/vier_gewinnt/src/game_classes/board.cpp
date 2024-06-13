#include <iostream>

#include "board.hpp"
#include "../utility/parameter.hpp"

Board::Board()
{
   for (int i = 0; i < Parameter::height; i++)
   {
      for (int j = 0; j < Parameter::width; j++)
      {
         m_board[i][j] = Parameter::emptyCell;
      }
   }
}

void Board::printBoard() const
{
   std::cout << "----- Current Board -----" << std::endl;
   for (int i = 0; i < Parameter::height; i++)
   {
      std::cout << "      ";
      for (int j = 0; j < Parameter::width; j++)
      {
         std::cout << m_board[i][j] << " ";
      }
      std::cout << std::endl;
   }
}

bool Board::isGameOver() const
{
   // horizontally connected
   for (int i = 0; i < Parameter::height; i++)
   {
      for (int j = 0; j < Parameter::width - 3; j++)
      {
         if (m_board[i][j] == m_currentPlayerIcon && m_board[i][j + 1] == m_currentPlayerIcon && m_board[i][j + 2] == m_currentPlayerIcon && m_board[i][j + 3] == m_currentPlayerIcon)
         {
            return true;
         }
      }
   }
   // vertically connected
   for (int i = 0; i < Parameter::height - 3; i++)
   {
      for (int j = 0; j < Parameter::width; j++)
      {
         if (m_board[i][j] == m_currentPlayerIcon && m_board[i + 1][j] == m_currentPlayerIcon && m_board[i + 2][j] == m_currentPlayerIcon && m_board[i + 3][j] == m_currentPlayerIcon)
         {
            return true;
         }
      }
   }
   // descending DiagonalCheck
   for (int i = 3; i < Parameter::height; i++)
   {
      for (int j = 0; j < Parameter::width - 3; j++)
      {
         if (m_board[i][j] == m_currentPlayerIcon && m_board[i - 1][j + 1] == m_currentPlayerIcon && m_board[i - 2][j + 2] == m_currentPlayerIcon && m_board[i - 3][j + 3] == m_currentPlayerIcon)
         {
            return true;
         }
      }
   }
   // ascending DiagonalCheck
   for (int i = 3; i < Parameter::height; i++)
   {
      for (int j = 3; j < Parameter::width; j++)
      {
         if (m_board[i][j] == m_currentPlayerIcon && m_board[i - 1][j - 1] == m_currentPlayerIcon && m_board[i - 2][j - 2] == m_currentPlayerIcon && m_board[i - 3][j - 3] == m_currentPlayerIcon)
         {
            return true;
         }
      }
   }
   return false;
}

bool Board::placeStone(const int columnNum)
{
   bool moveWasLegal = false;
   bool columnNumOutOfRange = ((columnNum < 0) | (columnNum >= Parameter::width));
   if (columnNumOutOfRange)
   {
      return moveWasLegal;
   }

   for (int i = Parameter::height - 1; i >= 0; i--)
   {
      if (m_board[i][columnNum] == Parameter::emptyCell)
      {
         // change player icon to current one
         if (m_currentPlayerIcon == Parameter::iconOne)
         {
            m_currentPlayerIcon = Parameter::iconTwo;
         }
         else
         {
            m_currentPlayerIcon = Parameter::iconOne;
         }

         moveWasLegal = true;
         m_board[i][columnNum] = m_currentPlayerIcon;
         break;
      }
   }
   return moveWasLegal;
}

std::array<std::array<char, Parameter::width>, Parameter::height> Board::returnBoard() const
{
   return m_board;
}
