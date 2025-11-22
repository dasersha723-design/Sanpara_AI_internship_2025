#include <stdio.h>
#include <stdlib.h>

char board[3][3];  // The game board

// Function to initialize the board with empty spaces
void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Function to print the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won
char checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' '; // No winner yet
}

// Check if board is full
int isFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

// Function for player move
void playerMove() {
    int move;
    while (1) {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        if (move < 1 || move > 9) {
            printf("Invalid move! Choose between 1 and 9.\n");
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == ' ') {
            board[row][col] = 'X';
            break;
        } else {
            printf("That spot is taken! Try again.\n");
        }
    }
}

// Simple AI move — chooses first empty spot
void computerMove() {
    printf("\nComputer's turn...\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

// Main function to run the game
int main() {
    char winner = ' ';
    initBoard();

    printf("==== TIC-TAC-TOE ====\n");
    printBoard();

    while (1) {
        playerMove();
        printBoard();

        winner = checkWinner();
        if (winner != ' ' || isFull())
            break;

        computerMove();
        printBoard();

        winner = checkWinner();
        if (winner != ' ' || isFull())
            break;
    }

    if (winner == 'X')
        printf("\nYou win!\n");
    else if (winner == 'O')
        printf("\nComputer wins!\n");
    else
        printf("\nIt's a draw!\n");

    return 0;
}
