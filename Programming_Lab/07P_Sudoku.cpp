#include <iostream>
using namespace std;

#define N 4

void print_sudoku(int arr[N][N]) {
     cout << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
            cout << endl;
    }
            cout << endl;
}

bool isSafe(int sudoku[N][N], int row, int col, int num) {
    
    // Check if N is present in Column
    for (int x = 0; x < N; x++) {
        if (sudoku[row][x] == num) {
            return false;
        }
    }

    // Check if N is present in Row
    for (int x = 0; x < N; x++) {
        if (sudoku[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 2;
    int startCol = col - col % 2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (sudoku[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int sudoku[N][N], int row, int col) {
    if (row == N - 1 && col == N) {
        return true;
    }

    if (col == N) {
        row++;
        col = 0;
    }

    if (sudoku[row][col] != 0) {
        return solveSudoku(sudoku, row, col + 1);
    }

    for (int num = 1; num <= N; num++) {
        if (isSafe(sudoku, row, col, num)) {
            sudoku[row][col] = num;

            if (solveSudoku(sudoku, row, col + 1)) {
                return true;
            }
        }

        sudoku[row][col] = 0;
    }

    return false;
}

int main() {
    int sudoku[N][N];
    cout << "Enter the Sudoku puzzle:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sudoku[i][j];
        }
    }

    if (solveSudoku(sudoku, 0, 0)) {
        cout << "Solved sudoku puzzle:" << endl;
        print_sudoku(sudoku);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}


