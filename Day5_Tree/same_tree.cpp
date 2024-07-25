bool solve(TreeNode* p,TreeNode* q){
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr || q == nullptr) return false;

    if(p->val != q->val) return false;
    return solve(p->left,q->left) && solve(p->right,q->right);
}
bool isSameTree(TreeNode* p, TreeNode* q) {
    return solve(p,q);
}