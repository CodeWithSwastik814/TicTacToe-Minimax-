#include <iostream>
#include <cmath>
#include <cstdio>
#include "Functions.h"
#include <algorithm>


bool isMoving(char board[3][3]) {
    bool move;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                return true;   // found an empty cell, exit immediately
                move = true;
            }
        }
    }
    return false;   // checked all cells, none empty
    move = false;
}


int evaluate(char board[3][3]) {
    // Row 0
    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') return +10;
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') return -10;
    // Row 1
    if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') return +10;
    if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') return -10;
    // Row 2
    if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') return +10;
    if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') return -10;
    // Column 0
    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') return +10;
    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') return -10;
    // Column 1
    if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') return +10;
    if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') return -10;
    // Column 2
    if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') return +10;
    if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') return -10;
    // Diagonal (top-left to bottom-right)
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return +10;
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return -10;
    // Anti-diagonal (top-right to bottom-left)
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') return +10;
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') return -10;

    return 0;
}


int minimax(char board[3][3], int depth, bool isMaximizing) {
    int score = evaluate(board);

    if (score == 10) return score - depth;   // O won — prefer faster win
    if (score == -10) return score + depth;  // X won — prefer slower loss
    if (!isMoving(board)) return 0;          // no moves left, draw

    if (isMaximizing) {
        int best = -1000;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == ' ') {
                    board[row][col] = 'O';                              // try move
                    best = std::max(best, minimax(board, depth + 1, false));
                    board[row][col] = ' ';                              // undo move
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == ' ') {
                    board[row][col] = 'X';
                    best = std::min(best, minimax(board, depth + 1, true));
                    board[row][col] = ' ';
                }
            }
        }
        return best;
    }
}


void findBestMove(char board[3][3], int& bestRow, int& bestCol) {
    int bestValue = -1000;
    bestRow = -1;
    bestCol = -1;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = 'O';                    // bot is O, matching your evaluate()
                int moveVal = minimax(board, 0, false);    // root call: depth=0, opponent's turn next
                board[row][col] = ' ';                     // undo the trial move

                if (moveVal > bestValue) {
                    bestValue = moveVal;
                    bestRow = row;
                    bestCol = col;
                }
            }
        }
    }
}


