// Input: root = [3,1,4,null,2], k = 1
// Output: 1

class Solution {
    void inorder(TreeNode* root,vector<int> &ans){
        if(!root ) return ;

        if(root->left) inorder(root->left,ans);
        ans.push_back(root->val);
        if(root->right) inorder(root->right,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int res = ans[k-1];
        return res;
    }
}