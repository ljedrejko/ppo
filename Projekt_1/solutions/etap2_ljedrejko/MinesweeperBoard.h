#ifndef MINESWEEPER_PROJECT_MINESWEEPERBOARD_H
#define MINESWEEPER_PROJECT_MINESWEEPERBOARD_H
#include "Field.h"
#include <iostream>
enum GameMode  {DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

class MinesweeperBoard
{
    int mine_count;
    GameState game_state;
    GameMode game_mode;
    bool first_action;

public:

    Field board[100][100];
    public: int width;
    public: int height;

    MinesweeperBoard()=default;
    MinesweeperBoard(int width, int height, GameMode mode);
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
    GameState getGameState() const;
    void revealField(int x, int y);


};
#endif //UNTITLED_MINESWEEPERBOARD_H
