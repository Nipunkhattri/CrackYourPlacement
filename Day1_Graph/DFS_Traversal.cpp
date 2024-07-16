void solve(int i,vector<int> adj[],int V,vector<int> &ans,vector<int> &vis){
    vis[i] = 1;
    ans.push_back(i);
    for(auto it:adj[i]){
        if(!vis[it])
            solve(it,adj,V,ans,vis);
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> vis(V,0);
    solve(0,adj,V,ans,vis);
    return ans;
}

// Time Complexity: O(V+E)
// Space Complexity: O(V)