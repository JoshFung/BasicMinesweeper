#include "Minesweeper.h"

Minesweeper::Minesweeper() {
    beginningSettings();
    mainBoard = new Board(rows, cols, mines);
    mainBoard->printBoard();
}


Minesweeper::~Minesweeper() {
    delete mainBoard;
}


int Minesweeper::difficultyChoice(string ss) {
    if (ss == "Easy" || ss == "easy") {
        rows = cols = mines = 10;
        return 0;
    } else if (ss == "Medium" || ss == "medium") {
        rows = cols = 16;
        mines = 40;
        return 0;
    } else if (ss == "Hard" || ss == "hard") {
        rows = 30; 
        cols = 16;
        mines = 99;
        return 0;
    } else {
        return 1;
    }
}


void Minesweeper::beginningSettings() {
    string response;
    cout << "What difficulty would you like to play? Easy, Medium, or Hard: ";
    cin >> response;

    int flag = 1;
    while (flag == 1) {
        flag = difficultyChoice(response);
    }
    cout << "You will play on a " << rows << "x" << cols << " board, with " << mines << " mines." << endl;

    // game official starts
    gameState = true;
}


int Minesweeper::chooseTile() {
    int x = -1;
    int y = -1;
    
    do {
        cout << "Choose a tile, in an \"x y\" format. For example: \"5 2\": " << endl;
        cin >> x >> y;
        cout << endl << "Choosing the tile at " << x << " " << y << "." << endl;
    } while (mainBoard->revealedTileError(mainBoard->visualBoard[mainBoard->index(x, y)]));

    return mainBoard->index(x, y);
}


void Minesweeper::mainGame() {
    while (gameState == true) {
        
    }
}





