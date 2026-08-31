#include <iostream>
using namespace std;

int n, m;
int graph[20][20];
int color[20];

bool isSafe(int vertex, int c) {

    for (int i = 0; i < n; i++) {

        if (graph[vertex][i] &&
            color[i] == c) {

            return false;
        }
    }

    return true;
}

bool solve(int vertex) {

    if (vertex == n)
        return true;

    for (int c = 1; c <= m; c++) {

        if (isSafe(vertex, c)) {

            color[vertex] = c;

            if (solve(vertex + 1))
                return true;

            color[vertex] = 0;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    if (solve(0)) {

        cout << "Vertex colors:\n";

        for (int i = 0; i < n; i++)
            cout << "Vertex " << i
                 << " = Color "
                 << color[i] << endl;

    } else {

        cout << "No solution";
    }

    return 0;
}
