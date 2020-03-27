#include <stdlib.h>
#include <time.h>
#include "MinesweeperBoard.h"
#include <iostream>
#include "MSBoardTextView.h"



int main() {
    srand (time(nullptr));
    MinesweeperBoard Board(10, 10, NORMAL);
    Board.debug_display();

    MinesweeperBoard board(10,10,NORMAL);
    MSBoardTextView view(board);
    view.display();

    return 0;
}
