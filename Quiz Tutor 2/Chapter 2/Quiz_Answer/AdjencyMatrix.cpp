#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9;

// add edge
void addEdge(vector<vector<double>> &mat, int i, int j, double distance) {
    mat[i][j] = distance;
}

// print adjacency matrix
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

    // set diagonal to 0
    for (int i = 0; i < V; i++)
        mat[i][i] = 0.0;

    // add edges with weights
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

    displayMatrix(mat);

    return 0;
}
