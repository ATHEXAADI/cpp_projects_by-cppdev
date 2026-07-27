#ifndef BOARD_H_
#define BOARD_H_

constexpr int SIZE = 3;
constexpr char DIGITS[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

class Board
{
public:
    Board() = default;
    ~Board() = default;

    void init();               // init board
    void draw();               // draw board on screen
    bool check();              // check win condition
    bool update(int position); // populate with mark

private:
    char board_[SIZE][SIZE];
    char mark_;
};

#endif