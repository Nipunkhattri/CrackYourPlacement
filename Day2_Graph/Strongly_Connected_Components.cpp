//  (Kosaraju's Algo)

// reverse the edges 

void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[i] = 1;
    for (auto it : adj[i]) {
        if (!vis[it]) {
            dfs(it, adj, vis, st);
        }
    }
    st.push(i);
}

void dfsT(int i, vector<vector<int>>& adjT, vector<int>& vis) {
    vis[i] = 1;
    for (auto it : adjT[i]) {
        if (!vis[it]) {
            dfsT(it, adjT, vis);
        }
    }
}


int kosaraju(int V, vector<vector<int>>& adj)
{
    vector<int> vis(V, 0);
    stack<int> st;
    
    // First DFS to fill the stack with vertices in the order of completion times
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
    
    // Create the transpose of the graph
    vector<vector<int>> adjT(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }
    
    // Reset the visited array for the second DFS
    fill(vis.begin(), vis.end(), 0);
    int scc = 0;
    
    // Process all vertices in the order defined by the stack
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            scc++;
            dfsT(node, adjT, vis);
        }
    }
    return scc;
}