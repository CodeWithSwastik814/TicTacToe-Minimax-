#include <iostream>
#include "Functions.cpp"
#include "minmax.cpp"

int main() {
    char gameBoard[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    showingBoard(gameBoard);

    while (true) {
        // Human turn
        playerInput(gameBoard);
        showingBoard(gameBoard);

        char winner = checkWin(gameBoard);
        if (winner == 'X') {
            std::cout << "You win!\n";
            break;
        }
        if (!isMoving(gameBoard)) {
            std::cout << "It's a draw!\n";
            break;
        }

        // Bot turn
        int botRow, botCol;
        findBestMove(gameBoard, botRow, botCol);
        gameBoard[botRow][botCol] = 'O';
        showingBoard(gameBoard);

        winner = checkWin(gameBoard);
        if (winner == 'O') {
            std::cout << "Bot wins!\n";
            break;
        }
        if (!isMoving(gameBoard)) {
            std::cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}