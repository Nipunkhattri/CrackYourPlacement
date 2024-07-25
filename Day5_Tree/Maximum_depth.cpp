int solve(TreeNode* root){
    if(root == nullptr) return 0; 
    int lh = solve(root->left);
    int rh = solve(root->right);
    return 1+max(lh,rh);
}
int maxDepth(TreeNode* root) {
    return solve(root);
}