#pragma once

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <ctime>
using std::time;


class Board {
    public:
        Board();
        ~Board();

        char printTile(int tile);
        void topRowVisualBoard();
        void mainVisualBoard();
        void printBoard();

        int nearbyMines(int pos);
        int checkUpperRow(int pos);
        int checkCurrentRow(int pos);
        int checkLowerRow(int pos);
        void initiateBoard();
        void initiateMines();


        int boardCols;
        int boardRows;
        int totalTiles;
        int mineCount;
        int* visualBoard;
        int* valueBoard;
    
    private:
        

};


class Minesweeper {
    public:
        Minesweeper();
        ~Minesweeper();

        int difficultyChoice(string ss);
        void beginningSettings();

    private:
        Board mainBoard;
};


