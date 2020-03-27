#ifndef MINESWEEPER_PROJECT_MSBOARDTEXTVIEW_H
#define MINESWEEPER_PROJECT_MSBOARDTEXTVIEW_H
#include <iostream>
#include "MinesweeperBoard.h"

class MSBoardTextView {

    MinesweeperBoard &mine_board;

    public:
        MSBoardTextView (MinesweeperBoard& board);
        void display() const;
        
};


#endif //MINESWEEPER_PROJECT_MSBOARDTEXTVIEW_H
