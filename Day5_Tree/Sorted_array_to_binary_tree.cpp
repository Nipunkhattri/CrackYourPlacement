TreeNode* solve(const vector<int>& nums, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = solve(nums, start, mid - 1);
    root->right = solve(nums, mid + 1, end);
    return root;
}