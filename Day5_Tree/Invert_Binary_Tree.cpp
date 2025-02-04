TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return nullptr;
    TreeNode* x = root->left;
    root->left = root->right;
    root->right = x;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}