bool isInside(int x, int y, int N) {
    return (x >= 1 && x <= N && y >= 1 && y <= N);
}

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    
    queue<pair<int, pair<int, int>>> q;
    
    q.push({0, {KnightPos[0], KnightPos[1]}});
    
    vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));
    
    visited[KnightPos[0]][KnightPos[1]] = true;
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        
        int dist = t.first;
        int x = t.second.first;
        int y = t.second.second;
        
        if (x == TargetPos[0] && y == TargetPos[1])
            return dist;
    
        // Check for all possible moves
        for (int i = 0; i < 8; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            if (isInside(x1, y1, N) && !visited[x1][y1]) {
                visited[x1][y1] = true;
                q.push({dist + 1, {x1, y1}});
            }
        }
    }
    return -1;
}