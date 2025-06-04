#include <bits/stdc++.h>
using namespace std;

// Function to add an edge between two vertices 
void addEdge (vector<vector<int>>& adj, int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i); // Undirected
}

// Function to display the adjacency list
void displayAdjList (const vector<vector<int>>& adj) { for (int i = 0; i < adj.size(); i++) {
        cout << i << ": "; // Print the vertex 
        for (int j : adj[i]) {
            cout << j << " "; // Print its adjacent
        }
        cout << endl;
    }
}


// Function to perform Breadth-First Search (BFS) 
void bfs(const vector<vector<int>> &adj, int start) {
    vector<bool> visited(adj.size(), false); // Track visited nodes 
    queue<int> q; // Queue for BFS traversal
    
    visited[start] = true; // Mark the starting node as visited 
    q.push(start); // Push the starting node into the queue
    
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front(); // Get the front node
        q.pop(); // Remove the front node from the queue 
        cout << node << " "; // Print the current node
        
        // Visit all neighbors of the current node 
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) { // If not visited
                visited[neighbor] = true; // Mark as visited 
                q.push(neighbor); // Push to the queue for further traversal
            }
        }
    }
    cout << endl;
}

// Depth-First Search (DFS) function (Recursive)
void dfsHelper(const vector<vector<int>> &adj, int node, vector<bool> &visited) { 
    visited[node] = true;
    cout << node << " "; // Print the current node
    
    // Recursively visit all unvisited neighbors 
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(adj, neighbor, visited);
        }
    }
}

// Wrapper function to initiate DFS traversal
void dfs(const vector<vector<int>> &adj, int start) {
    vector<bool> visited(adj.size(), false); // Track visited nodes
    cout << "DFS Traversal: ";
    dfsHelper(adj, start, visited); 
    cout << endl;
}

// Main function 
int main() {
    // Create a graph with 4 vertices and no edges
    int V = 4;
    vector<vector<int>> adj (V);
    
    // Now add edges one by one
    addEdge (adj, 0, 1);
    addEdge (adj, 0, 2);
    addEdge (adj, 1, 2);
    addEdge (adj, 2, 3);
    
    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);
    
    bfs(adj, 3);
    dfs(adj, 1);
    
    return 0;
}
