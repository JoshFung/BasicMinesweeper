#include "Minesweeper.h"


Board::Board() {
    boardCols = boardRows = mineCount = totalTiles = 0;
    initiateBoard();
}


Board::~Board() {
    delete [] visualBoard;
    delete [] valueBoard;
}


Board::Board(int rows, int cols, int mines) {
    boardRows = rows;
    boardCols = cols;
    mineCount = mines;
    totalTiles = 0;
    initiateBoard();
}


char Board::printTile(int tile) {
    if (tile == 0) {
        return ' ';
    } else if (tile == -1 || tile == -3) {
        return '-';
    } else if (tile == -2) {
        return ' ';
    } else if (tile == -4) {
        return 'X';
    } else if (tile == -5) {
        return 'F';
    } else {
        return (char)tile;
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
                    cout << "  ";
                    cout << printTile(valueBoard[index(k, j)]);
                } else {
                    cout << "   ";
                    cout << printTile(valueBoard[index(k, j)]);
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


int Board::checkUpperRow(int x, int y) {
    int count = 0;

    // if we are at the top of the board
    if (y == 0) {
        return count;
    }

    // if x isn't the far left of the board
    if (x != 0) {
        if (valueBoard[index(x-1, y-1)] == -3 || valueBoard[index(x-1, y-1)] == -4) {
            count++;
        }
    }

    // if x isn't the far right of the board
    if (x != boardCols-1) {
        if (valueBoard[index(x+1, y-1)] == -3 || valueBoard[index(x+1, y-1)] == -4) {
            count++;
        }
    }

    // check the element above
    if (valueBoard[index(x, y-1)] == -3 || valueBoard[index(x, y-1)] == -4) {
        count++;
    }

    // return the count
    return count;
}


int Board::checkCurrentRow(int x, int y) {
    int count = 0;

    // if it isn't the far left of the board, 
    if (x != 0) {
        if (valueBoard[index(x-1, y)] == -3 || valueBoard[index(x-1, y)] == -4) {
            count++;
        }
    }

    if (x != boardCols-1) {
        if (valueBoard[index(x+1, y)] == -3 || valueBoard[index(x+1, y)] == -4) {
            count++;
        }
    }

    return count;
}


int Board::checkLowerRow(int x, int y) {
    int count = 0;

    if (y == boardRows-1) {
        return count;
    }

    if (x != 0) {
        if (valueBoard[index(x-1, y+1)] == -3 || valueBoard[index(x-1, y+1)] == -4) {
            count++;
        }
    }

    if (x != boardCols-1) {
        if (valueBoard[index(x+1, y+1)] == -3 || valueBoard[index(x+1, y+1)] == -4) {
            count++;
        }
    }

    if (valueBoard[index(x, y+1)] == -3 || valueBoard[index(x, y+1)] == -4) {
        count++;
    }

    return count;
}


int Board::index(int x, int y) {
    return (y*boardCols + x);
}


int Board::nearbyMines(int x, int y) {
    int count = 0;

    count += checkCurrentRow(x, y);
    count += checkUpperRow(x, y);
    count += checkLowerRow(x, y);

    return count;
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
    for (int i = 0; i < totalTiles+1; i++) {
        visualBoard[i] = -1;
        valueBoard[i] = -1;
    }

    // set the mines into valueBoard
    initiateMines();

    // set values for all other tiles
    for (int j = 0; j < boardCols; j++) {
        for (int k = 0; k < boardRows; k++) {
            valueBoard[index(j, k)] = nearbyMines(j, k);
        }
    }

}