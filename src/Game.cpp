#include "Game.h"
#include <iostream>

Game::Game(const Board& board) :
    board_(board)
{
}

void Game::run()
{
    board_.init();
    int moves = 0;
    int position = 0;
    
    while (moves < 9)
    {
        std::cout << "\n TicTacToe ! \n";
        board_.draw();
        
        std::cout << "\n Player " << (moves % 2 ? "2" : "1") << "'s turn:\n";
        
        std::cin >> position;
        
        while (position > 9 || position < 1)
        {
            std::cout << "\nInvalid input. Please use numbers between 1 and 9!\n";
            std::cin >> position;
        }
        
        while (!board_.update(position))
        {
            std::cout << "\nProbably there is already X or O at the given position \nInvalid input. Try again with a valid position!\n";
            std::cin >> position;
        }
        
        // check if somebody won only if more than 4 moves already
        if (moves > 4)
        {
            if (board_.check())
            {
                board_.draw();
                std::cout << "Player " << (moves % 2 ? "2" : "1") << " won!\n";
                break;
            }
            else if (moves == 8)
            {
                board_.draw();
                std::cout << "\nIt's a draw!\n";
                break;
            }
        }
        
        moves++;
    }
}