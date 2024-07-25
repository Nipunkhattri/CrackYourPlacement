void solve(TreeNode* root, int col, int row, map<int, map<int, multiset<int>>> &mp) {
    if (root == nullptr) return;
    mp[col][row].insert(root->val);
    solve(root->left, col-1, row+1, mp);
    solve(root->right, col+1, row+1, mp);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> mp;
    solve(root, 0, 0, mp);
    vector<vector<int>> ans;
    for (auto col : mp) {
        vector<int> colVec;
        for (auto row : col.second) {
            colVec.insert(colVec.end(), row.second.begin(), row.second.end());
        }
        ans.push_back(colVec);
    }
    return ans;
}