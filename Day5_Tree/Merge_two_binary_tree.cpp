TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr) return root2; 
    if (root2 == nullptr) return root1;
    int a = root1->val;
    int b = root2->val;
    int node = a+b;
    TreeNode* root = new TreeNode(node);
    root->left = mergeTrees(root1->left,root2->left);
    root->right = mergeTrees(root1->right,root2->right);
    return root;
}