bool solve(TreeNode* root, int targetSum) {
    // If we reach a null node, return false
    if (root == nullptr) return false;
    
    // Check if we've reached a leaf node and the targetSum equals the leaf's value
    if (root->left == nullptr && root->right == nullptr) {
        return root->val == targetSum;
    }
    
    // Subtract the current node's value from targetSum and recurse
    targetSum -= root->val;
    return solve(root->left, targetSum) || solve(root->right, targetSum);
}
bool hasPathSum(TreeNode* root, int targetSum) {
    return solve(root,targetSum);
}