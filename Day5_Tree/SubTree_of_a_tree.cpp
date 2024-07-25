bool isSameTree(TreeNode* s, TreeNode* t) {
    if (s == nullptr && t == nullptr) return true;
    if (s == nullptr || t == nullptr) return false;
    return (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}
bool solve(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) return false;
    if (isSameTree(root, subRoot)) return true;
    return solve(root->left, subRoot) || solve(root->right, subRoot);
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    return solve(root,subRoot);
}