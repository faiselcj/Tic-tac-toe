#include <iostream>
#include <vector>
using namespace std;

// Class for managing the Tic Tac Toe game
class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    // Constructor to initialize the board and starting player
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    // Display the current board
    void displayBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "--|---|--" << endl;
        }
    }

    // Check if the move is valid
    bool isValidMove(int row, int col) {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    // Make a move on the board
    void makeMove(int row, int col) {
        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    // Check if there's a winner
    bool checkWinner(char player) {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;

        return false;
    }

    // Check if the board is full (draw)
    bool isDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    // Start the game
    void startGame() {
        cout << "Welcome to Tic Tac Toe!" << endl;
        displayBoard();

        while (true) {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            makeMove(row - 1, col - 1);
            displayBoard();

            if (checkWinner('X')) {
                cout << "Player X wins!" << endl;
                break;
            }
            if (checkWinner('O')) {
                cout << "Player O wins!" << endl;
                break;
            }
            if (isDraw()) {
                cout << "It's a draw!" << endl;
                break;
            }
        }
    }
};

// Main function
int main() {
    TicTacToe game;
    game.startGame();
    return 0;
}
