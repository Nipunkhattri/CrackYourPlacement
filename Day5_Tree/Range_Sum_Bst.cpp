void Inorder(TreeNode* root,vector<int> &ans){
    if(root == NULL) return ;

    Inorder(root->left,ans);
    ans.push_back(root->val);
    Inorder(root->right,ans);
}
int rangeSumBST(TreeNode* root, int low, int high) {
    vector<int> ans;
    Inorder(root,ans);
    int val = 0;
    for(int i=0;i<ans.size();i++){
        if(ans[i]>=low && ans[i]<=high){
            val += ans[i];
        }
    }
    return val;
}