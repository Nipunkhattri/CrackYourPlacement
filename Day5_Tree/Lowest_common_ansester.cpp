TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
    if(p->val == root->val || q->val == root->val) return root;

    if(p->val < root->val && q->val < root->val){
        return solve(root->left,p,q);
    }
    else if(p->val > root->val && q->val > root->val){
        return solve(root->right,p,q);
    }
    return root;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return solve(root,p,q);
}