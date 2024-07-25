// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

int widthOfBinaryTree(TreeNode* root) {
    if(root == nullptr) return 0;

    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    int max_width = 0;
    while(!q.empty()){
        int s = q.size();
        int start = q.front().second;
        int end = q.back().second;

        cout<<start<<" "<<end<<" "<<max_width<<'\n';

        max_width = max(max_width,(end-start+1));
        for(int i=0;i<s;i++){
            TreeNode* node = q.front().first;
            int val = q.front().second;
            q.pop();

            if(node->left){
                q.push({node->left, 2 * val});
            }
            if(node->right){
                q.push({node->right, 2 * val + 1});
            }
        }
    }
    return max_width;
}

