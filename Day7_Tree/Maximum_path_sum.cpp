// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.


int solve(TreeNode* root,int &maxi){
    if(root == nullptr) return 0;
    int lh = max(0,solve(root->left,maxi));
    int rh = max(0,solve(root->right,maxi));
    int x = root->val;
    maxi = max(maxi,x+lh+rh);
    return x + max(lh,rh);
}
int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    solve(root,maxi);
    return maxi;
}