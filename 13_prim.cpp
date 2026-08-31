#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int graph[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    const int INF = 1000000000;

    int key[100];
    int parent[100];
    bool used[100] = {};

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < n; count++) {

        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!used[i] &&
                (u == -1 || key[i] < key[u])) {

                u = i;
            }
        }

        if (u == -1)
            break;

        used[u] = true;

        for (int v = 0; v < n; v++) {

            if (graph[u][v] > 0 &&
                !used[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    cout << "Edges in MST:\n";

    for (int i = 1; i < n; i++) {

        cout << parent[i]
             << " - " << i
             << " : " << key[i]
             << endl;

        total += key[i];
    }

    cout << "MST cost = " << total;

    return 0;
}
