void dfs(vector<vector<int>>& adj, vector<int>& visited, int node) {
    visited[node] = 1; // Mark node as visited
    for (int neighbor : adj[node]) {
        if (visited[neighbor] == 0) { // If neighbor hasn't been visited
            dfs(adj, visited, neighbor); // Recursively visit neighbor
        }
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    if (n - 1 > connections.size()) {
        return -1; // Not enough edges to connect all nodes
    }
    vector<vector<int>> adj(n);

    for (auto& conn : connections) {
        adj[conn[0]].push_back(conn[1]);
        adj[conn[1]].push_back(conn[0]);
    }

    vector<int> visited(n, 0);
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) { 
            components++;
            dfs(adj, visited, i);
        }
    }
    return components - 1;
}