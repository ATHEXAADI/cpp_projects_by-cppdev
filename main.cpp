#include <iostream>
#include "Board.h"
#include "Game.h"

int main()
{
    Board board;
    Game game(board);
    
    game.run();
    
    return 0;
}