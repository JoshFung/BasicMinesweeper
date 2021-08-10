#include "Minesweeper.h"

Minesweeper::Minesweeper() {
    beginningSettings();
    mainBoard = new Board(rows, cols, mines);
    // mainBoard->printBoard();
    mainGame();
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


int Minesweeper::endGameCheck(int idx) {
    if (mainBoard->visualBoard[idx] == -2) {
        // game over -> bomb detonated
        return -1;
    } else {
        for (int i = 0; i < (rows * cols); i++) {
            if (mainBoard->valueBoard[idx] != -2 && mainBoard->visualBoard[idx] == -3) {
                // game continues -> still unexposed blanks
                return 0;
            }
        }

        // game over -> all non-bomb tiles have been exposed
        return 1;
    }
}


void Minesweeper::mainGame() {
    int idx = -99;
    char mode = 'z';
    int endCheck = -99;

    while (gameState == true) {
        idx = -1;
        mode = 'z';

        mainBoard->printBoard();
        chooseTile(idx, mode);
        changeTile(idx, mode);        

        if (mode == 'R') {
            endCheck = endGameCheck(idx);

            if (endCheck == -1) {
                cout << endl << "Game over! You detonated a mine!" << endl;
                mainBoard->printBoardExposed();
                gameState = false;
            } else if (endCheck == 1) {
                cout << endl << "Congratulations! You have avoided all the mines!" << endl;
                mainBoard->printBoardExposed();
                gameState = false;
            }
        }

    }
}

