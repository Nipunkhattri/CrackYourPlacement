//  Construct Binary Tree from Preorder and Postorder Traversal

TreeNode* solve(int& preIndex, vector<int>& preorder, int start, int end, unordered_map<int, int>& postIndexMap) {
    if (start > end) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(preorder[preIndex++]);
    cout<<start<<" "<<end<<" "<<root->val<<'\n';

    if (start == end) {
        return root;
    }
    
    int nextValue = preorder[preIndex];//2 4
    int postIndex = postIndexMap[nextValue];// 0
    cout<<nextValue<<postIndex<<'\n';

    if (postIndex <= end) {
        cout<<"left"<<preIndex<<" "<<start<<" "<<postIndex<<'\n';
        root->left = solve(preIndex, preorder, start, postIndex, postIndexMap);
        cout<<"Basis"<<'\n';
        cout<<"right"<<preIndex<<" "<<postIndex + 1<<" "<<end - 1<<'\n';
        root->right = solve(preIndex, preorder, postIndex + 1, end - 1, postIndexMap);
    }
    
    return root;
}
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    unordered_map<int, int> postIndexMap;
    for (int i = 0; i < postorder.size(); ++i) {
        postIndexMap[postorder[i]] = i;
    }
    
    int preIndex = 0;
    return solve(preIndex, preorder, 0, preorder.size() - 1, postIndexMap);
}