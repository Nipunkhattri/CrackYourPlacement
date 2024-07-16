bool solve(int i, vector<int> adj[], vector<int> &vis, int par) {
    vis[i] = 1;
    for (auto it : adj[i]) {
        if (!vis[it]) {
            if (solve(it, adj, vis, i)) {
                return true;
            }
        } else if (it != par) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (solve(i, adj, vis, -1)) {
                return true;
            }
        }
    }
    return false;
}

// Time Complexity:O(V+E)
// Space Complexity:O(V)