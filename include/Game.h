#ifndef GAME_H_
#define GAME_H_

#include "Board.h"

class Game
{
public:
    Game() = default;
    ~Game() = default;

    Game(const Board& board);

    void run();

private:
    Board board_;
};

#endif