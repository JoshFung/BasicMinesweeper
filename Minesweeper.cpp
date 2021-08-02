#include "Minesweeper.h"

Minesweeper::Minesweeper() {
    beginningSettings();
    mainBoard.printBoard();
}


Minesweeper::~Minesweeper() {

}


int Minesweeper::difficultyChoice(string ss) {
    if (ss == "Easy" || ss == "easy") {
        mainBoard.boardRows = mainBoard.boardCols = mainBoard.mineCount = 10;
        return 0;
    } else if (ss == "Medium" || ss == "medium") {
        mainBoard.boardRows = mainBoard.boardCols = 16;
        mainBoard.mineCount = 40;
        return 0;
    } else if (ss == "Hard" || ss == "hard") {
        mainBoard.boardRows = 30; 
        mainBoard.boardCols = 16;
        mainBoard.mineCount = 99;
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
    cout << "You will play on a " << mainBoard.boardRows << "x" << mainBoard.boardCols << " board, with " << mainBoard.mineCount << " mines." << endl;
}








