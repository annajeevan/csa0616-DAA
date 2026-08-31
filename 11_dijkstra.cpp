#include <iostream>
using namespace std;

int main() {
    int n, source;

    cin >> n;

    int graph[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cin >> source;

    const int INF = 1000000000;

    int dist[100];
    bool visited[100] = {};

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    for (int count = 0; count < n; count++) {

        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || dist[i] < dist[u])) {

                u = i;
            }
        }

        if (u == -1 || dist[u] == INF)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {

            if (graph[u][v] > 0 &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] =
                    dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << i << " : " << dist[i] << endl;

    return 0;
}
