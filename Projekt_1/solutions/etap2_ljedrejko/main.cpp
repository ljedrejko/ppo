#include <stdlib.h>
#include <time.h>
#include "MinesweeperBoard.h"

int main() {
    srand (time(nullptr));

    MinesweeperBoard Board;

    Board.debug_display();
    std::cout<<Board.getBoardHeight()<<std::endl;
    std::cout<<Board.getBoardWidth()<<std::endl;
    std::cout<<Board.getMineCount()<<std::endl;
    std::cout<<Board.countMines(4, 4)<<std::endl;
    std::cout<<Board.hasFlag(4,4 )<<std::endl;
    std::cout<<Board.isRevealed(4, 4)<<std::endl;
    std::cout<<Board.getFieldInfo(4, 4)<<std::endl;
    Board.toggleFlag(4, 4);
    return 0;
}
