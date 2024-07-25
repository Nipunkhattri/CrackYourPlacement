void solve(TreeNode* root, vector<string> &ans, string s) {
    if (root == nullptr) {
        return;
    }
    // Append the current node's value to the path
    if (!s.empty()) {
        s += "->";
    }
    s += to_string(root->val);
    
    // If it's a leaf node, add the path to the answer
    if (root->left == nullptr && root->right == nullptr) {
        ans.push_back(s);
        return;
    }
    
    // Recur for left and right subtrees
    solve(root->left, ans, s);
    solve(root->right, ans, s);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string s = "";
    solve(root,ans,s);
    return ans;
}