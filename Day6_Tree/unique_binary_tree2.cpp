// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

vector<TreeNode*> solve(int start,int end){
    if(start > end) return {nullptr};

    if(start == end){
        TreeNode* root = new TreeNode(start);
        return {root};
    }
    vector<TreeNode*> result;
    for(int i = start;i<=end;i++){
        vector<TreeNode*> LeftBsts = solve(start,i-1);
        vector<TreeNode*> RightBsts = solve(i+1,end);

        for(TreeNode* leftRoot:LeftBsts){
            for(TreeNode* rightRoot:RightBsts){
                TreeNode* root = new TreeNode(i);
                root->left = leftRoot;
                root->right = rightRoot;

                result.push_back(root);
            }
        }
    }
    return result;
}
vector<TreeNode*> generateTrees(int n) {
    return solve(1,n);
}