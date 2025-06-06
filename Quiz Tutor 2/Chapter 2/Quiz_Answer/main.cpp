#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

// print path
void printPath(vector<int>& parent, int v) {
    if (parent[v] == -1) {
        cout << v;
        return;
    }
    printPath(parent, parent[v]);
    cout << " -> " << v;
}

// dijkstra algorithm
void dijkstra(const vector<vector<pair<int, double>>>& adjList, int start, int end) {
    int V = adjList.size();
    vector<double> dist(V, INF);
    vector<int> parent(V, -1);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [curDist, u] = pq.top();
        pq.pop();

        for (auto& [v, weight] : adjList[u]) {
            if (dist[v] > curDist + weight) {
                dist[v] = curDist + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distance from Home to Faculty of MIPA: " << dist[end] << " Km" << endl;
    cout << "Path: ";
    printPath(parent, end);
    cout << endl;
}

int main() {
    // Nodes
    vector<string> names = {
        "Home", "RSGM", "GSP", "Balairung UGM", "Faculty of MIPA"
    };

    int V = 5;
    
    // adjacency matrix
    vector<vector<double>> adjMatrix(V, vector<double>(V, INF));
    auto addEdgeMatrix = [&](int u, int v, double w) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    };

    addEdgeMatrix(0, 1, 4.4); // Home - RSGM
    addEdgeMatrix(0, 2, 4.4); // Home - GSP
    addEdgeMatrix(1, 4, 1.5); // RSGM - MIPA
    addEdgeMatrix(2, 1, 2.1); // GSP - RSGM
    addEdgeMatrix(2, 3, 0.5); // GSP - Balairung
    addEdgeMatrix(2, 4, 2.1); // GSP - MIPA
    addEdgeMatrix(3, 4, 1.9); // Balairung - MIPA

    cout << "Adjacency Matrix :" << endl;
    for (int i = 0; i < V; i++) {
        cout << names[i] << ": ";
        for (int j = 0; j < V; j++) {
            if (adjMatrix[i][j] == INF) cout << "INF ";
            else cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // adjacency list
    vector<vector<pair<int, double>>> adjList(V);
    auto addEdgeList = [&](int u, int v, double w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    };

    addEdgeList(0, 1, 4.4);
    addEdgeList(0, 2, 4.4);
    addEdgeList(1, 4, 1.5);
    addEdgeList(2, 1, 2.1);
    addEdgeList(2, 3, 0.5);
    addEdgeList(2, 4, 2.1);
    addEdgeList(3, 4, 1.9);

    cout << "\nAdjacency List :" << endl;
    for (int i = 0; i < V; i++) {
        cout << names[i] << ": ";
        for (auto& [v, w] : adjList[i]) {
            cout << "(" << names[v] << ", " << w << " Km) ";
        }
        cout << endl;
    }

    // dijkstra from Home (0) to Faculty of MIPA (4)
    cout << "\nDijkstra Shortest Path :" << endl;
    dijkstra(adjList, 0, 4);

    return 0;
}

