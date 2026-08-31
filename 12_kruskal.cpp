#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[100];

int findSet(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findSet(parent[x]);
}

int main() {
    int V, E;

    cin >> V >> E;

    Edge edges[500];

    for (int i = 0; i < E; i++)
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].w;

    sort(edges, edges + E, compare);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int total = 0;
    int count = 0;

    cout << "Edges in MST:\n";

    for (int i = 0; i < E && count < V - 1; i++) {

        int u = findSet(edges[i].u);
        int v = findSet(edges[i].v);

        if (u != v) {

            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].w << endl;

            total += edges[i].w;

            parent[u] = v;
            count++;
        }
    }

    cout << "MST cost = " << total;

    return 0;
}
