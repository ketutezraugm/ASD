#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9; // Representing infinity

void addEdge(vector<vector<double>> &mat, int i, int j, double distance) {
    mat[i][j] = distance;
}

void displayMatrix(vector<vector<double>> &mat) {
    int V = mat.size();

    cout << "Adjacency Matrix Representation" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (mat[i][j] >= INF)
                cout << "∞ ";
            else
                cout << fixed << setprecision(1) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<double>> mat(V, vector<double>(V, INF));

    // Set diagonal to 0
    for (int i = 0; i < V; i++)
        mat[i][i] = 0.0;

    // Add edges with weights
    addEdge(mat, 0, 1, 4.4); // Home -> GSP
    addEdge(mat, 0, 2, 4.4); // Home -> RSGM

    addEdge(mat, 1, 0, 4.4);
    addEdge(mat, 1, 2, 2.1);
    addEdge(mat, 1, 3, 0.5);
    addEdge(mat, 1, 4, 2.1);

    addEdge(mat, 2, 0, 4.4);
    addEdge(mat, 2, 1, 2.1);
    addEdge(mat, 2, 4, 1.5);

    addEdge(mat, 3, 1, 0.5);
    addEdge(mat, 3, 4, 1.9);

    addEdge(mat, 4, 1, 2.1);
    addEdge(mat, 4, 2, 1.5);
    addEdge(mat, 4, 3, 1.9);

    displayMatrix(mat);

    return 0;
}
