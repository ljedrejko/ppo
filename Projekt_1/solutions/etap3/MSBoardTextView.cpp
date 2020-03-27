#include <iostream>
#include <stdlib.h>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <iomanip>

MSBoardTextView::MSBoardTextView(MinesweeperBoard& board): mine_board(board){}

void MSBoardTextView::display() const{
    for(int i=0; i<this->mine_board.width; i++)
    {
        for(int j=0; j<this->mine_board.height; j++)
        {
            if(mine_board.board[i][j].isRevealed)
            {
                if (mine_board.board[i][j].hasMine) {
                    std::cout<< std::setw(3) << "x";
                }
                else if (!mine_board.board[i][j].hasMine && mine_board.countMines(i, j) != 0)
                {
                    std::cout<< std::setw(3)<<mine_board.countMines(i,j);
                }
            }
             else{
                if(mine_board.board[i][j].hasFlag)
                {
                    std::cout<< std::setw(3)<<"F";
                }
                else {
                    std::cout << std::setw(3) << "_";
                }

            }
        }
        std::cout<<std::endl;
    }
}
