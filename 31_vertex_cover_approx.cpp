#include <iostream>
using namespace std;

int main() {
    int V, E;

    cin >> V >> E;

    int u[500], v[500];

    bool cover[100] = {};

    for (int i = 0; i < E; i++)
        cin >> u[i] >> v[i];

    for (int i = 0; i < E; i++) {

        if (!cover[u[i]] &&
            !cover[v[i]]) {

            cover[u[i]] = true;
            cover[v[i]] = true;
        }
    }

    cout << "Approximate Vertex Cover: ";

    for (int i = 0; i < V; i++) {

        if (cover[i])
            cout << i << " ";
    }

    return 0;
}
