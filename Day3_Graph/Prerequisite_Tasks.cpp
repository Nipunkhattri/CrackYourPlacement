bool dfs(int i, vector<vector<int>>& adj, vector<int>& Vis, vector<int>& pathVis) {
    Vis[i] = 1;
    pathVis[i] = 1;
    for (auto it : adj[i]) {
        if (!Vis[it]) {
            if (dfs(it, adj, Vis, pathVis)) {
                return true;
            }
        } else if (pathVis[it] == 1) {
            return true;
        }
    }
    pathVis[i] = 0;
    return false;
}
bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
    vector<vector<int>> adj(N);
    for (auto it : prerequisites) {
        adj[it.second].push_back(it.first);
    }
    vector<int> pathVis(N,0);
    vector<int>Vis(N,0);
    for(int i =0 ;i< N;i++){
        if(dfs(i,adj,Vis,pathVis)){
            return false;
        }
    }
    return true;
}
