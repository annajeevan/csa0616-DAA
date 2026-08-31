#include <iostream>
using namespace std;

int board[9][9];

bool isSafe(int row, int col, int num) {

    for (int i = 0; i < 9; i++) {

        if (board[row][i] == num)
            return false;

        if (board[i][col] == num)
            return false;
    }

    int startRow =
        row - row % 3;

    int startCol =
        col - col % 3;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (board[
                    startRow + i
                ][
                    startCol + j
                ] == num)

                return false;
        }
    }

    return true;
}

bool solveSudoku() {

    for (int row = 0; row < 9; row++) {

        for (int col = 0; col < 9; col++) {

            if (board[row][col] == 0) {

                for (int num = 1;
                     num <= 9;
                     num++) {

                    if (isSafe(
                            row,
                            col,
                            num)) {

                        board[row][col] = num;

                        if (solveSudoku())
                            return true;

                        board[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main() {

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    if (solveSudoku()) {

        cout << "Solved Sudoku:\n";

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";

            cout << endl;
        }

    } else {

        cout << "No solution";
    }

    return 0;
}
