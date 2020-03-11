#ifndef GABENFREEMAN9_MINESWEEPERBOARD_H
#define GABENFREEMAN9_MINESWEEPERBOARD_H
#include "Field.h"
#include <iostream>

class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;
public:
    void wymiary();
    MinesweeperBoard(int width=10, int height=10);
    void debug_display() const;
};


#endif
