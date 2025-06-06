#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9;

// add edge
void addEdge(vector<vector<double>> &mat, int i, int j, double distance) {
    mat[i][j] = distance;
}

// find the vertex with shortest path
int minDistance(vector<double> &dist, vector<bool> &visited) {
    double min = INF;
    int min_index = -1;

    for (int v = 0; v < dist.size(); v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// dijkstra’s algorithm
void dijkstra(vector<vector<double>> &graph, int src) {
    int V = graph.size();
    vector<double> dist(V, INF);
    vector<bool> visited(V, false);

    dist[src] = 0.0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] < INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print shortest distances from source
    cout << "Shortest distances from source (node " << src << "):\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << ": ";
        if (dist[i] >= INF)
            cout << "Unreachable\n";
        else
            cout << fixed << setprecision(1) << dist[i] << "\n";
    }
}

int main() {
    int V = 5;
    vector<vector<double>> mat(V, vector<double>(V, INF));

    // set diagonal to 0
    for (int i = 0; i < V; i++)
        mat[i][i] = 0.0;

    // index mapping:
    // 0 - Home
    // 1 - GSP
    // 2 - RSGM
    // 3 - Balairung UGM
    // 4 - Faculty of MIPA

    // add edges
    addEdge(mat, 0, 1, 4.4); // Home -> GSP
    addEdge(mat, 0, 2, 4.4); // Home -> RSGM

    addEdge(mat, 1, 0, 4.4); // GSP -> Home
    addEdge(mat, 1, 2, 2.1); // GSP -> RSGM
    addEdge(mat, 1, 3, 0.5); // GSP -> Balairung UGM
    addEdge(mat, 1, 4, 2.1); // GSP -> Faculty of MIPA

    addEdge(mat, 2, 0, 4.4); // RSGM -> Home
    addEdge(mat, 2, 1, 2.1); // RSGM -> GSP
    addEdge(mat, 2, 4, 1.5); // RSGM -> Faculty of MIPA

    addEdge(mat, 3, 1, 0.5); // Balairung UGM -> GSP
    addEdge(mat, 3, 4, 1.9); // Balairung UGM -> Faculty of MIPA

    addEdge(mat, 4, 1, 2.1); // Faculty of MIPA -> GSP
    addEdge(mat, 4, 2, 1.5); // Faculty of MIPA -> RSGM
    addEdge(mat, 4, 3, 1.9); // Faculty of MIPA -> Balairung UGM

    // call dijkstra algorithm
    dijkstra(mat, 0);

    return 0;
}
