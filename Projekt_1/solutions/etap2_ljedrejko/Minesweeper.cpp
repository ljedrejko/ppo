#include "MinesweeperBoard.h"
#include <iostream>
#include <stdlib.h>


MinesweeperBoard::MinesweeperBoard( int width,  int height, GameMode mode)
{
    this->first_action=true;
    this->width=width;
    this->height=height;

    for(int i=0; i<this->width; i++)
    {
        for(int j=0; j<this->height; j++)
        {
            board[i][j].hasMine=false;
            board[i][j].isRevealed=false;
            board[i][j].hasFlag=false;
        }
    }
    
    this->game_state = RUNNING;
    this->game_mode = mode;

    float percent=0;

    if (this->game_mode==DEBUG)
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
    else if (this->game_mode==EASY)
    {
        percent=0.1;
    }
    else if (this->game_mode==NORMAL)
    {
        percent=0.2;
    }
    else if (this->game_mode==HARD)
    {
        percent=0.3;
    }

    int mines_left = width*height*percent;
    
    while (mines_left>0)
    {
        int a = rand()%height;
        int b = rand()%width;
        if (!board[a][b].hasMine)
        {
            board[a][b].hasMine = true;
            mines_left--;
        }
    }
};

void MinesweeperBoard::debug_display() const
{
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
    return MinesweeperBoard::width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return this->height;
}

int MinesweeperBoard::getMineCount() const
{
    int how_many_mines=0;
    for (int i=0; i<this->width;i++)
    {
        for (int j=0; j<this->height; j++)
        {
            if (this->board[i][j].hasMine)
            {
                how_many_mines++;
            }
        }
    }
    return how_many_mines;

}
bool MinesweeperBoard::isOutside(int x, int y) const
{
    if (x>=this->width||y>=this->height || x<0 || y<0) {
        return true;
    }
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

                if(!isOutside((x-1+i), (y+j-1) ) ){
                    if (MinesweeperBoard::board[x - 1 + i][y + j - 1].hasMine){
                        mines++;
                    }
                }
            }
        }
         if (MinesweeperBoard::board[x][y].hasMine) {
            mines--;
        }
        return mines;
    }
}
bool MinesweeperBoard::hasFlag(int x, int y) const{

    if ( (MinesweeperBoard::board[x][y].isRevealed) || isOutside(x,y) )
    {
        return false;
    }

    if (MinesweeperBoard::board[x][y].hasFlag)
    {
        return true;
    }else{
        return false;
    }
}
bool MinesweeperBoard::isRevealed(int x, int y) const { // if outside returns 0
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

}

void MinesweeperBoard::toggleFlag(int x, int y)
{
    if (isOutside(x,y)||isRevealed(x,y)|| this->game_state==(FINISHED_WIN||FINISHED_LOSS) ) {
        return;
    }
    this->board[x][y].hasFlag = !this->board[x][y].hasFlag;

}

GameState MinesweeperBoard::getGameState() const
{
    return this->game_state;
}

void MinesweeperBoard::revealField(int x, int y)
{
    if (isOutside(x,y) || hasFlag(x,y) || isRevealed(x,y) || this->game_state==(FINISHED_WIN||FINISHED_LOSS))
    {
        return;
    }

    if (this->board[x][y].hasMine){
        int a,b;
        if (this->first_action){
            this->board[x][y].hasMine=false;


            while (true){
                a = rand()%height;
                b = rand()%width;
            
                if (!board[a][b].hasMine){
                    this->board[a][b].hasMine = true;
                    this->board[a][b].isRevealed=true;
                    break;
                }
            }

        }else{
            this->board[x][y].isRevealed=true;
            this->game_state=FINISHED_LOSS;
        }

    }else{
        this->board[x][y].isRevealed=true;
    }

    this->first_action=false;

}


