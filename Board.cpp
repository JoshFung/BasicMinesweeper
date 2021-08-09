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
    if (tile == 0 || tile == -3) {
        return ' ';
    } else if (tile ==-1) {
        return '-';
    } else if (tile == -2) {
        return 'X';
    } else if (tile == -4) {
        return 'F';
    } else {
        return tile+48;
    }
}


bool Board::checkExposed(int tile) {
    if (visualBoard[tile] == 1) {
        return true;
    } else {
        return false;
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
            if (k == 0) {
                cout << "  " << j+1;
            } else {
                if (j >= 9 && k == 1) {
                    cout << "  ";
                    cout << printTile(visualBoard[index(k-1, j)]);
                } else {
                    cout << "   ";
                    cout << printTile(visualBoard[index(k-1, j)]);
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}


void Board::exposedVisualBoard() {
    cout << endl;
    for (int j = 0; j < boardRows; j++) {
        for (int k = 0; k < boardCols + 1; k++) {
            // if (k == 0 && j < 10) {
            //     cout << "  " << j+1;
            // } else if (k == 0 && j >= 10) {
            //     cout << "  " << j+1;

            // testing
            if (k == 0) {
                cout << "  " << j+1;
            } else {
                if (j >= 9 && k == 1) {
                    cout << "  ";
                    cout << printTile(valueBoard[index(k-1, j)]);
                } else {
                    cout << "   ";
                    cout << printTile(valueBoard[index(k-1, j)]);
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

    // temporary
    topRowVisualBoard();
    exposedVisualBoard();
}


int Board::checkUpperRow(int x, int y) {
    int count = 0;

    // if we are at the top of the board
    if (y == 0) {
        return count;
    }

    // if x isn't the far left of the board
    if (x != 0) {
        if (valueBoard[index(x-1, y-1)] == -2 || valueBoard[index(x-1, y-1)] == -2) {
            count++;
        }
    }

    // if x isn't the far right of the board
    if (x != boardCols-1) {
        if (valueBoard[index(x+1, y-1)] == -2 || valueBoard[index(x+1, y-1)] == -2) {
            count++;
        }
    }

    // check the element above
    if (valueBoard[index(x, y-1)] == -2 || valueBoard[index(x, y-1)] == -2) {
        count++;
    }

    // return the count
    return count;
}


int Board::checkCurrentRow(int x, int y) {
    int count = 0;

    // if it isn't the far left of the board, 
    if (x != 0) {
        if (valueBoard[index(x-1, y)] == -2 || valueBoard[index(x-1, y)] == -2) {
            count++;
        }
    }

    if (x != boardCols-1) {
        if (valueBoard[index(x+1, y)] == -2 || valueBoard[index(x+1, y)] == -2) {
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
        if (valueBoard[index(x-1, y+1)] == -2 || valueBoard[index(x-1, y+1)] == -2) {
            count++;
        }
    }

    if (x != boardCols-1) {
        if (valueBoard[index(x+1, y+1)] == -2 || valueBoard[index(x+1, y+1)] == -2) {
            count++;
        }
    }

    if (valueBoard[index(x, y+1)] == -2 || valueBoard[index(x, y+1)] == -2) {
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

    // cout << "bomb count " << count << endl;
    return count;
}


void Board::initiateMines() {
    srand((int)time(0));
    for (int i = 0; i < mineCount; i++) {
        valueBoard[rand() % totalTiles] = -2;
    }
    for (int j = 0; j < totalTiles; j++) {
        if (valueBoard[j] == -2) {
            visualBoard[j] = -1;
        }
    }
}


void Board::initiateBoard() {
    totalTiles = boardRows * boardCols;
    visualBoard = new int[totalTiles];
    valueBoard = new int[totalTiles];

    // set each tile as unexposed blanks
    for (int i = 0; i < totalTiles+1; i++) {
        visualBoard[i] = -1;
        valueBoard[i] = -1;
    }

    // set the mines into valueBoard
    initiateMines();

    // set values for all other tiles
    for (int j = 0; j < boardCols; j++) {
        for (int k = 0; k < boardRows; k++) {
            if (valueBoard[index(j, k)] != -2) {
                valueBoard[index(j, k)] = nearbyMines(j, k);
                visualBoard[index(j, k)] = -1;
            }
        }
    }

}


bool Board::exposedError(int tile) {
    if (visualBoard[tile] == -3) {
        cout << endl << "The tile is already exposed!" << endl;
        return true;
    } else {
        return false;
    }
}


bool Board::flagError(int tile) {
    if (visualBoard[tile] == -4) {
        cout << endl << "The tile is flagged!" << endl;
        return true;
    } else {
        return false;
    }
}