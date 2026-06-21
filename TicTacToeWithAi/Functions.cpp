#include "Functions.h"
#include <iostream>
#include <limits>


char checkWin(char board[3][3]) {
        // ---- Check X ----
        // Rows
        for (int row = 0; row < 3; row++) {
            if (board[row][0] == 'X' && board[row][1] == 'X' && board[row][2] == 'X') {
                return 'X';
            }
        }
        // Columns
        for (int col = 0; col < 3; col++) {
            if (board[0][col] == 'X' && board[1][col] == 'X' && board[2][col] == 'X') {
                return 'X';
            }
        }
        // Diagonals
        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
            return 'X';
        }
        if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
            return 'X';
        }

        // ---- Check O ----
        // Rows
        for (int row = 0; row < 3; row++) {
            if (board[row][0] == 'O' && board[row][1] == 'O' && board[row][2] == 'O') {
                return 'O';
            }
        }
        // Columns
        for (int col = 0; col < 3; col++) {
            if (board[0][col] == 'O' && board[1][col] == 'O' && board[2][col] == 'O') {
                return 'O';
            }
        }
        // Diagonals
        if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
            return 'O';
        }
        if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
            return 'O';
        }

        return ' '; // no winner yet
}


void showingBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << "   |    ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "-------------------" << std::endl;
    }
}


void printInstructions() {
    std::cout << "Player 1 Turn\n";
    std::cout << " 1 | 2 | 3 \n";
    std::cout << " 4 | 5 | 6 \n";
    std::cout << " 7 | 8 | 9 \n";
    std::cout << "Enter position (1-9): ";
}



void playerInput(char board[3][3]) {
    int choice;
    bool validMove = false;

    do {
        printInstructions();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                if (board[0][0] == ' ') { board[0][0] = 'X'; validMove = true; break; }
                else std::cout << "Postion Already Taken.";
                break;
            case 2:
                if (board[0][1] == ' ') { board[0][1] = 'X'; validMove = true; break; }
                else std::cout << "Postion Already Taken.";
                break;
            case 3:
                if (board[0][2] == ' ') { board[0][2] = 'X'; validMove = true; break; }
                else std::cout << "Postion Already Taken.";
                break;
            case 4:
                if (board[1][0] == ' ') { board[1][0] = 'X'; validMove = true; break; }
                else std::cout << "Postion Already Taken.";
                break;
            case 5:
                if (board[1][1] == ' ') { board[1][1] = 'X'; validMove = true; break; }
                else std::cout << "Postion Already Taken.";
                break;
            case 6:
                if (board[1][2] == ' ') { board[1][2] = 'X'; validMove = true; break; }
                else std::cout << "Postion Already Taken.";
                break;
            case 7:
                if (board[2][0] == ' ') { board[2][0] = 'X'; validMove = true; break; }
                else std::cout << "Postion Already Taken.";
                break;
            case 8:
                if (board[2][1] == ' ') { board[2][1] = 'X'; validMove = true; break; }
                else std::cout << "Postion Already Taken.";
                break;
            case 9:
                if (board[2][2] == ' ') { board[2][2] = 'X'; validMove = true; break; }
                else std::cout << "Postion Already Taken.";
                break;
            default:
                std::cout << "Invalid choice.";
        }
    } while (!validMove);
}