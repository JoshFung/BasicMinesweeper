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


void Minesweeper::chooseTile(int & idx, char & mode) {
    int x = -1;
    int y = -1;
    char md = 'z';
    bool flag = false;

    do {
        x = y = -1;
        md = 'z';
        flag = false;

        cout << "Reveal(R) or Flag(F) a tile, in a \"x y <R/F>\" format. For example: \"5 2 R\": " << endl;
        cin >> x >> y >> md;

        // if the tile is invalid
        if (mainBoard->invalidTile(x, y) == true) {
            // flag remains false

        // if we are to reveal a tile
        } else if (md == 'R' || md == 'r') {
            // check if the tile is already revealed
            if (mainBoard->exposedError(mainBoard->index(x,y)) == true) {
                flag = false;
            } else {
                cout << endl << "Revealing the tile at " << x << " " << y << "." << endl;
                idx = mainBoard->index(x,y);
                mode = 'R';
                flag = true;
            }
            
        } else if (md == 'F' || md == 'f') {
            if (mainBoard->flagError(mainBoard->index(x,y)) == true) {
                flag = false;
            } else if (mainBoard->visualBoard[mainBoard->index(x,y)] == -4) {
                cout << endl << "Unflagging the tile at " << x << " " << y << "." << endl;
                idx = mainBoard->index(x,y);
                mode = 'F';
                flag = true;
            } else {
                cout << endl << "Flagging the tile at " << x << " " << y << "." << endl;
                idx = mainBoard->index(x,y);
                mode = 'F';
                flag = true;
            }

        } else {
            cout << endl << "Incorrect mode! Please choose 'R' or 'F'!" << endl;
            // flag remains false
        }

    } while (flag == false);

}


void Minesweeper::changeTile(int idx, char mode) {
    // error checking is done prior, so just need to change tiles

    // reveal tile
    if (mode == 'R') {
        mainBoard->visualBoard[idx] = mainBoard->valueBoard[idx];

    // flag / unflag tile
    } else {
        if (mainBoard->visualBoard[idx] == -4) {
            mainBoard->visualBoard[idx] = -3;
        } else {
            mainBoard->visualBoard[idx] = -4;
        }
    }
}


void Minesweeper::mainGame() {
    int idx = -1;
    char mode = 'z';

    while (gameState == true) {
        idx = -1;
        mode = 'z';

        chooseTile(idx, mode);
        changeTile(idx, mode);

    }
}





