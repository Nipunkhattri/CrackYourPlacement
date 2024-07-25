// 199. Binary Tree Right Side View

// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == nullptr) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int  s = q.size();
        ans.push_back(q.back()->val);
        for(int i=0;i<s;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return ans;
}