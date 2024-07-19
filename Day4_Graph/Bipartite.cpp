bool dfs(int i, vector<int> adj[], vector<int>& Vis,int prev) {
    Vis[i] = prev;
    for(auto it:adj[i]){
        if(Vis[it] == -1){
            if(dfs(it,adj,Vis,!prev) == false) return false;
        }
        else if(Vis[it] == prev){
            return false;
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[]) {
    vector<int> Vis(V, -1);
    for (int i = 0; i < V; i++) {
        if (Vis[i] == -1) {
            if (dfs(i, adj, Vis,0) == false) {
                return false;
            }
        }
    }
    return true;
}