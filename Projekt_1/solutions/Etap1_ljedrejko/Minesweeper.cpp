#include "MinesweeperBoard.h"
#include <iostream>
#include <stdlib.h>


MinesweeperBoard::MinesweeperBoard( int width,  int height)
{
    this->width=width;
    this->height=height;

    for(int i=0; i<this->width; i++)
    {
        for(int j=0; j<this->height; j++)
        {
            board[i][j].hasMine=0;
            board[i][j].isRevealed=0;
            board[i][j].hasFlag=0;
        }
    }
};

void MinesweeperBoard::debug_display() const
{
    std::cout<<"Wymiary ["<<this->width<<"]["<<this->height<<"]"<<std::endl;

    for(int i=0; i<this->width; i++)
    {
        for(int j=0; j<this->height; j++)
        {
            std::cout<<"{";
            if(board[i][j].hasMine) {
                std::cout << "M";
            }
            else {
                std::cout<<".";
            }
            if(board[i][j].isRevealed){
                std::cout<<"O";
            }
            else {
                std::cout<<".";
            }
            if(board[i][j].hasFlag){
                std::cout<<"F";
            }
            else {
                std::cout<<".";
            }
            std::cout<<"}";
        }
        std::cout<<std::endl;
    }
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
