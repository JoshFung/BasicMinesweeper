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
    char mode = 'z';
    bool flag = false;

    do {
        x = -1;
        y = -1;
        mode = 'z';
        flag = false;

        cout << "Reveal(R) or Flag(F) a tile, in a \"x y <R/F>\" format. For example: \"5 2 R\": " << endl;
        cin >> x >> y >> mode;
        cout << endl << "Choosing the tile at " << x << " " << y << "." << endl;

        // if the tile is invalid
        if (mainBoard->invalidTile(x, y) == true) {
            flag = false;

        // if we are to reveal a tile
        } else if (mode == 'R' || mode == 'r') {
            // check if the tile is already revealed
            if (mainBoard->exposedError(mainBoard->index(x,y)) == true) {
                flag = false;
            } else {
                
            }
            
        } else if (mode == 'F' || mode == 'f') {

        } else {
            cout << endl << "Incorrect mode! Please choose 'R' or 'F'!" << endl;
        }


    } while (flag == false);

    return mainBoard->index(x, y);
}


void Minesweeper::mainGame() {
    while (gameState == true) {
        
    }
}





