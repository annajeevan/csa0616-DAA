#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int V, E, source;

    cin >> V >> E;

    Edge edge[500];

    for (int i = 0; i < E; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;

    cin >> source;

    const int INF = 1000000000;

    int dist[100];

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++) {

        for (int j = 0; j < E; j++) {

            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;

            if (dist[u] != INF &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {

        int u = edge[j].u;
        int v = edge[j].v;
        int w = edge[j].w;

        if (dist[u] != INF &&
            dist[u] + w < dist[v]) {

            cout << "Negative weight cycle exists";
            return 0;
        }
    }

    cout << "Shortest distances:\n";

    for (int i = 0; i < V; i++)
        cout << i << " : " << dist[i] << endl;

    return 0;
}
