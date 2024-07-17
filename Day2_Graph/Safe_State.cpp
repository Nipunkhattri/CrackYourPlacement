bool dfs(int i, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
    vis[i] = 1;
    pathVis[i] = 1;
    for (auto it : graph[i]) {
        if (!vis[it]) {
            if (dfs(it, graph, vis, pathVis, check)) {
                check[i] = 0;
                return true;
            }
        } else if (pathVis[it] == 1) {
            check[i] = 0;
            return true;
        }
    }
    check[i] = 1;
    pathVis[i] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, graph, vis, pathVis, check);
        }
    }
    vector<int> safeNodes;
    for (int i = 0; i < V; i++) {
        if (check[i] == 1) {
            safeNodes.push_back(i);
        }
    }
    return safeNodes;
}