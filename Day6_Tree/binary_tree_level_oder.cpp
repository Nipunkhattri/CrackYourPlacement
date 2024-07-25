// Binary Tree Level Order Traversal

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int s = q.size();
        vector<int> ans;
        for (int i = 0; i < s; ++i) {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        res.push_back(ans);
    }

    return res;
}