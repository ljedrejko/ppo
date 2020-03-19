#include "MinesweeperBoard.h"
#include <iostream>
#include <stdlib.h>


MinesweeperBoard::MinesweeperBoard( int width,  int height, GameMode mode)
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
    state=RUNNING;
    float percent=0;
    if (mode==DEBUG)
        for (int i=0; i<this->width;i++)
    {
        board[0][i].hasMine = true;
        for (int j=0; j<height; j++)
        {
            if (j==i)
                board[j][i].hasMine = true;
            board[2*j][0].hasMine = true;
        }
    }
    else if (mode==EASY)
    {
        percent=0.1;
    }
    else if (mode==NORMAL)
    {
        percent=0.2;
    }
    else if (mode==HARD)
    {
        percent=0.3;
    }
    mine_count=width*height*percent;

    int mine_amount=mine_count;
    while (mine_amount>0)
    {
        int a = rand()%height;
        int b = rand()%width;
        if (!board[a][b].hasMine)
        {
            board[a][b].hasMine = rand() % 2;
            if (board[a][b].hasMine)
                mine_amount--;
        }
    }
};

void MinesweeperBoard::debug_display() const
{
    std::cout<<"Board size "<<this->width<<"x"<<this->height<<std::endl;

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

int MinesweeperBoard::getBoardWidth() const
{
    std::cout<<"width: ";
    return MinesweeperBoard::width;
}

int MinesweeperBoard::getBoardHeight() const
{
    std::cout<<"height: ";
    return MinesweeperBoard::height;
}

int MinesweeperBoard::getMineCount() const
{
    int how_many_mines=0;
    std::cout<<"mines: ";
    for (int i=0; i<this->width;i++)
    {
        for (int j=0; j<this->height; j++)
        {
            if (MinesweeperBoard::board[i][j].hasMine)
            {
                how_many_mines++;
            }
        }
    }
    return how_many_mines;

}
bool MinesweeperBoard::isOutside(int x, int y) const
{
    if (x>this->width||y>this->height)
    {
        std::cout<<width;
        return true;
    }
    else
        return false;
}

int MinesweeperBoard::countMines(int x, int y) const {
    int mines = 0;
    if ((!MinesweeperBoard::board[y][x].isRevealed) || isOutside(x, y)) {
        return -1;
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (MinesweeperBoard::board[x - 1 + i][y + j - 1].hasMine)
                    mines++;
            }
        }
        if (MinesweeperBoard::board[x][y].hasMine) {
            mines--;
        }
        return mines;

    }
}
bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if ((MinesweeperBoard::board[x][y].isRevealed)||isOutside(x,y)||(!MinesweeperBoard::board[y][x].hasFlag))
    {
        return false;
    }
    else if (MinesweeperBoard::board[x][y].hasFlag)
    {
        return true;
    }
}
bool MinesweeperBoard::isRevealed(int x, int y) const {
    if (MinesweeperBoard::board[y][x].isRevealed)
    {
        return true;
    }
    else
        {
            return false;
        }
}
char MinesweeperBoard::getFieldInfo(int x, int y) const {
    if (isOutside(x, y)) {
        return '#';
    }
    else if (!isRevealed(x, y) && hasFlag(x, y)) {
        return 'F';
    }
    else if (!isRevealed(x, y) && !hasFlag(x, y))
    {
        return '_';
    }
    else if (isRevealed(x, y) && MinesweeperBoard::board[y][x].hasMine) {
        return 'x';
    }
    else if (isRevealed(x, y) && countMines(x, y) == 0)
    {
        return ' ';
    }
    else if (isRevealed(x, y) && countMines(x, y) != 0)
    {
        return countMines(x, y);
    }
    else
        {
        return '?';
        }
}

void MinesweeperBoard::toggleFlag(int x, int y)
{
    if (isOutside(x,y)||isRevealed(x,y)||state==(FINISHED_WIN||FINISHED_LOSS)) {
        return;
    }
    else if (!isRevealed(x,y)&&hasFlag(x,y)) {
        MinesweeperBoard::board[y][x].hasFlag = false;
    }
    else if (!isRevealed(x,y)&&!hasFlag(x,y)) {
        MinesweeperBoard::board[y][x].hasFlag = true;
    }
}

