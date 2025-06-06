#include <iostream>
#include <vector>
using namespace std;

// add edge
void addEdge(vector<vector<pair<int, double>>>& adj, int i, int j, double weight) {
    adj[i].push_back({j, weight});
}

// print the adjacency list
void displayAdjList(const vector<vector<pair<int, double>>>& adj) {
    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (auto& p : adj[i]) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<pair<int, double>>> adj(V);

    // index node
    // 0 - Home
    // 1 - GSP
    // 2 - RSGM
    // 3 - Balairung UGM
    // 4 - Faculty of MIPA

    addEdge(adj, 0, 1, 4.4); // Home -> GSP
    addEdge(adj, 0, 2, 4.4); // Home -> RSGM

    addEdge(adj, 1, 2, 2.1); // GSP -> RSGM
    addEdge(adj, 1, 3, 0.5); // GSP -> Balairung
    addEdge(adj, 1, 4, 2.1); // GSP -> Faculty of MIPA

    addEdge(adj, 2, 4, 1.5); // RSGM -> Faculty of MIPA

    addEdge(adj, 3, 4, 1.9); // Balairung -> Faculty of MIPA

    displayAdjList(adj);

    return 0;
}

