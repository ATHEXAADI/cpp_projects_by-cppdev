#include "Board.h"
#include <iostream>

void Board::init()
{
    mark_ = 'X';
    int digit = 1;
    for (auto line = 0; line < SIZE; line++)
    {
        for (auto column = 0; column < SIZE; column++)
        {
            board_[line][column] = DIGITS[digit++];
        }
    }
}

void Board::draw()
{
    std::cout << "\n";
    for (auto line = 0; line < SIZE; line++)
    {
        std::cout << " | ";
        for (auto column = 0; column < SIZE; column++)
        {
            std::cout << board_[line][column] << " | ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool Board::check()
{
    int i = 0;
    int j = 0;
    
    // check lines
    if (board_[i][j] == board_[i][j+1] && board_[i][j] == board_[i][j+2])
        return true;
    
    i = 1;
    if (board_[i][j] == board_[i][j+1] && board_[i][j] == board_[i][j+2])
        return true;
        
    i = 2;
    if (board_[i][j] == board_[i][j+1] && board_[i][j] == board_[i][j+2])
        return true;
        
    // check columns
    i = 0;
    if (board_[i][j] == board_[i+1][j] && board_[i][j] == board_[i+2][j])
        return true;
        
    j = 1;
    if (board_[i][j] == board_[i+1][j] && board_[i][j] == board_[i+2][j])
        return true;
        
    j = 2;
    if (board_[i][j] == board_[i+1][j] && board_[i][j] == board_[i+2][j])
        return true;
        
    // check diags
    i = 0;
    j = 0;
    if (board_[i][j] == board_[i+1][j+1] && board_[i][j] == board_[i+2][j+2])
        return true;
        
    i = 0;
    j = SIZE - 1;
    if (board_[i][j] == board_[i+1][j-1] && board_[i][j] == board_[i+2][j-2])
        return true;
        
    return false;
}

bool Board::update(int position)
{
    bool updated = false;
    for (auto line = 0; line < SIZE; line++)
    {
        for (auto column = 0; column < SIZE; column++)
        {
            if (board_[line][column] == DIGITS[position])
            {
                board_[line][column] = mark_;
                updated = true;
            }
        }
    }
    
    // change mark only if updated
    if (updated)
    {
        if (mark_ == 'X')
            mark_ = 'O';
        else
            mark_ = 'X';
    }
    
    return updated;
}