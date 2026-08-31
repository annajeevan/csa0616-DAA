#include <iostream>
using namespace std;

int n;
int graph[20][20];
int path[20];

bool isSafe(int vertex, int position) {

    if (!graph[path[position - 1]][vertex])
        return false;

    for (int i = 0; i < position; i++) {

        if (path[i] == vertex)
            return false;
    }

    return true;
}

bool solve(int position) {

    if (position == n) {

        return graph[path[n - 1]][path[0]];
    }

    for (int v = 1; v < n; v++) {

        if (isSafe(v, position)) {

            path[position] = v;

            if (solve(position + 1))
                return true;
        }
    }

    return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    path[0] = 0;

    if (solve(1)) {

        cout << "Hamiltonian Cycle:\n";

        for (int i = 0; i < n; i++)
            cout << path[i] << " ";

        cout << path[0];

    } else {

        cout << "No Hamiltonian Cycle";
    }

    return 0;
}
