#include "MinesweeperBoard.h"
#include <stdlib.h>
#include <time.h>

MinesweeperBoard::MinesweeperBoard(int width, int height)
{
    this->width=width;
    this->height=height;
    setField_Clear();
};

void MinesweeperBoard::debug_display() const
{
    std::cout<<"Wymiary:"<<this->width<<"x"<<this->height<<"\n";
    std::cout<<"--------------------------------------------------\n";
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<this->height; j++)
        {
            std::cout<<"{";
            if(board[i][j].hasMine==1) std::cout<<"M";
            else std::cout<<".";
            if(board[i][j].isRevealed==1) std::cout<<"o";
            else std::cout<<".";
            if(board[i][j].hasFlag==1) std::cout<<"F";
            else std::cout<<".";
            std::cout<<"}";
        }
        std::cout<<"\n";
    }
    std::cout<<"--------------------------------------------------\n";
}

void MinesweeperBoard::setField_Rand()
{
    for(int i=0; i<this->width; i++)
    {
        for(int j=0; j<this->height; j++)
        {
            board[i][j].hasMine=rand() % 2;
            board[i][j].isRevealed=rand() % 2;
            board[i][j].hasFlag=rand() % 2;
        }
    }
}
void MinesweeperBoard::setField_Clear()
{
    for(int i=0; i<this->width; i++)
    {
        for(int j=0; j<this->height; j++)
        {
            board[i][j].hasMine=0;
            board[i][j].isRevealed=0;
            board[i][j].hasFlag=0;
        }
    }
}
