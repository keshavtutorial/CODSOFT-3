#include <iostream>
using namespace std;


void printBoard(char board[3][3]) {
    cout << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool checkWin(char board[3][3], char player) {
    
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { 
            return true;
        }
    }
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}


bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {  
                return false;
            }
        }
    }
    return true;  
}


bool isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}


void playGame() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        cout << "Player " << currentPlayer << "'s turn." << endl;


        cout << "Enter row (0, 1, 2): ";
        cin >> row;
        cout << "Enter column (0, 1, 2): ";
        cin >> col;

        if (isValidMove(board, row, col)) {
            board[row][col] = currentPlayer;
        } else {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }
        
        else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        }

        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();  
    } else {
        cout << "Thanks for playing!" << endl;
    }
}

int main() {
    playGame();  
    return 0;
}
