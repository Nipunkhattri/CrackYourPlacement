vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int x, int y, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& dp) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    int max_count = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[x][y]) {
            max_count = max(max_count, 1 + solve(nx, ny, matrix, n, m, dp));
        }
    }

    dp[x][y] = max_count;
    return max_count;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int max_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            max_count = max(max_count, solve(i, j, matrix, n, m, dp));
        }
    }
    return max_count;
}