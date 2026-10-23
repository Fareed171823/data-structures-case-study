#include <iostream>
#include <climits>
using namespace std;

const int V = 4;

int main() {
    int graph[V][V] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    int parent[V];
    int key[V];
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX;
        int u = -1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        if (u == -1) {
            cout << "All cities cannot be connected!\n";
            return 0;
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;

    cout << "Roads selected:\n";

    for (int i = 1; i < V; i++) {
        cout << "City " << parent[i] + 1
             << " - City " << i + 1
             << " : Cost " << graph[i][parent[i]] << '\n';

        totalCost += graph[i][parent[i]];
    }

    cout << "Minimum cost to connect all cities: "
         << totalCost << '\n';

    return 0;
}
