// 530. Minimum Absolute Difference in BST
void solve(TreeNode* root,vector<int> &ans){
    if(root == nullptr) return;
    solve(root->left,ans);
    ans.push_back(root->val);
    solve(root->right,ans);
}
int getMinimumDifference(TreeNode* root) {
    vector<int> ans;
    solve(root,ans);
    int i, minDiff=INT_MAX, size, diff;
    size = ans.size();
    for (i = 1; i < size; ++i) {
        diff = ans[i] - ans[i-1];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}