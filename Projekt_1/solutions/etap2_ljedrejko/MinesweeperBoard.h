#ifndef MINESWEEPER_PROJECT_MINESWEEPERBOARD_H
#define MINESWEEPER_PROJECT_MINESWEEPERBOARD_H
#include "Field.h"
#include <iostream>

class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;
    int mine_count;
    GameState state;

public:
    MinesweeperBoard(int width=10, int height=10, GameMode mode=NORMAL);
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    bool isOutside(int x, int y) const;
    int countMines(int x, int y) const;
    bool hasFlag(int x, int y) const;
    bool isRevealed(int x, int y) const;
    char getFieldInfo(int x, int y) const;
    void toggleFlag(int x, int y);
};
#endif //UNTITLED_MINESWEEPERBOARD_H

