#include "Minesweeper.h"


Board::Board() {
    boardCols = boardRows = mineCount = totalTiles = 0;
}


Board::~Board() {
    delete [] visualBoard;
    delete [] valueBoard;
}


char Board::printTile(int tile) {
    if (tile == -1 || tile == -3) {
        return '-';
    } else if (tile == -2) {
        return ' ';
    } else if (tile == -4) {
        return 'X';
    } else if (tile == -5) {
        return 'F';
    } else {
        return (char)(tile+48);
    }
}


void Board::topRowVisualBoard() {
    cout << "   ";
    for (int i = 0; i < boardCols; i++) {
        if (i < 10) {
            cout << "   " << i+1; 
        } else {
            cout << "  " << i+1;
        }
    }
}


void Board::mainVisualBoard() {
    cout << endl;
    for (int j = 0; j < boardRows; j++) {
        for (int k = 0; k < boardCols + 1; k++) {
            if (k == 0 && k < 10) {
                cout << "  " << j+1;
            } else if (k == 0 && k >= 10) {
                cout << " " << j+1;
            } else {
                if (j >= 9 && k == 1) {
                    cout << "  -";
                } else {
                    cout << "   -";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}


void Board::printBoard() {
    cout << endl;
    topRowVisualBoard();
    mainVisualBoard();

}


int Board::checkUpperRow(int pos) {
    int count = 0;
    if (((pos - boardCols) >= 0) && (valueBoard[pos-boardCols] == -3)) {
        count++;
    }
    if (((pos-boardCols-1) >= 0) && (valueBoard[pos-boardCols] == -3)) {
        count++;
    }
}


int Board::checkCurrentRow(int pos) {
    int count = 0;
    if (((pos % boardCols) != 0) && (valueBoard[pos-1] == -3)) {
        count++;
    }
    if (((pos+1 % boardCols) != 0) && (valueBoard[pos+1] == -3)) {
        count++;
    }
    return count;
}


int Board::checkLowerRow(int pos) {

}


int Board::nearbyMines(int pos) {
    int count = 0;

    count += checkCurrentRow(pos);
    count += checkUpperRow(pos);
    count += checkLowerRow(pos);
}


void Board::initiateMines() {
    srand((int)time(0));
    for (int i = 0; i < totalTiles; i++) {
        valueBoard[rand() % totalTiles] = -3;
    }
}


void Board::initiateBoard() {
    totalTiles = boardRows * boardCols;
    visualBoard = new int[totalTiles];
    valueBoard = new int[totalTiles];

    // set each tile as unexposed
    for (int i = 0; i < totalTiles; i++) {
        visualBoard[i] = -1;
    }

    // set the mines into valueBoard
    initiateMines();

    // set values for all other tiles
    for (int j = 0; j < totalTiles; j++) {

    }

}