#ifndef FUNCTIONS_H
#define FUNCTIONS_H

char checkWin(char board[3][3]);
void showingBoard(char board[3][3]);
void printInstructions();
void playerInput(char board[3][3]);
bool isMoving(char board[3][3]);
int evaluate(char board[3][3]);
int minimax(char board[3][3], int depth, bool isMaximizing);
void findBestMove(char board[3][3], int& bestRow, int& bestCol);

#endif // FUNCTIONS_H