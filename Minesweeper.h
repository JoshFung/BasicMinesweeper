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
        Board(int rows, int cols, int mines);

        char printTile(int tile);
        void topRowVisualBoard();
        void mainVisualBoard();
        void exposedVisualBoard();
        void printBoard();
        void printBoardExposed();

        int index(int x, int y);
        int nearbyMines(int x, int y);
        int checkUpperRow(int x, int y);
        int checkCurrentRow(int x, int y);
        int checkLowerRow(int x, int y);
        void initiateBoard();
        void initiateMines();
        bool checkExposed(int tile);
        bool revealedTileError(int tile);
        bool revealTile(int tile);


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
        int chooseTile();
        void mainGame();
        

    private:
        Board* mainBoard;
        int rows;
        int cols;
        int mines;
        bool gameState;
};


