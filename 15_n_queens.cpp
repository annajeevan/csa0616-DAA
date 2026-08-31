#include <iostream>
using namespace std;

int n;
int board[20];

bool isSafe(int row, int col) {

    for (int i = 0; i < row; i++) {

        if (board[i] == col)
            return false;

        if (abs(board[i] - col) ==
            abs(i - row))
            return false;
    }

    return true;
}

void solve(int row) {

    if (row == n) {

        for (int i = 0; i < n; i++)
            cout << board[i] + 1 << " ";

        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {

        if (isSafe(row, col)) {

            board[row] = col;

            solve(row + 1);
        }
    }
}

int main() {
    cin >> n;

    solve(0);

    return 0;
}
