#include "MinesweeperBoard.h"
MinesweeperBoard::MinesweeperBoard(int width, int height)
{
    this->width=width;
    this->height=height;
};

void MinesweeperBoard::wymiary()
{
    std::cout<<width<<"\n"<<height;
}