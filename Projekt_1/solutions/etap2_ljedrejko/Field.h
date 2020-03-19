#ifndef MINESWEEPER_PROJECT_FIELD_H
#define MINESWEEPER_PROJECT_FIELD_H
enum GameMode  {DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};


#endif //UNTITLED_FIELD_H
