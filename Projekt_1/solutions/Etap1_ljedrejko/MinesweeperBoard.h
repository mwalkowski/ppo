#ifndef MINESWEEPER_PROJECT_MINESWEEPERBOARD_H
#define MINESWEEPER_PROJECT_MINESWEEPERBOARD_H
#include "Field.h"
#include <iostream>

class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;

public:
    MinesweeperBoard(int width=10, int height=10);
    void debug_display() const;
    void setField_Rand();
};
#endif //UNTITLED_MINESWEEPERBOARD_H

