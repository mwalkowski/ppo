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
    MinesweeperBoard(int width=10, int height=10);
    void debug_display() const; //show board
    void setField_Rand(); //set random values on every field
    void setField_Clear(); //set values=0 on every field (using in constructor)
};


#endif
