bool solve(TreeNode* rootLeft,TreeNode* rootRight) {
    if(rootLeft == nullptr && rootRight == nullptr) return true;
    if(rootLeft == nullptr || rootRight == nullptr) return false;

    return (rootLeft->val == rootRight->val) && solve(rootLeft->right,rootRight->left) && solve(rootLeft->left , rootRight->right); 
}
bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    return solve(root->left,root->right);
}