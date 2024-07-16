vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);//Taking visited Array
    queue<int> q;// Initializing queue
    q.push(0);
    vector<int> ans;
    visited[0] = 1; 
    while(!q.empty()){
        int node  = q.front();
        ans.push_back(node);// pushing node to ans array
        q.pop();
        for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;// setting node visited
            }
        }
    }
    return ans;
}
// T.C = O(V+E)
// S.C = O(V)