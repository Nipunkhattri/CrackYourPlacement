vector<int> zigzagLevelOrderTraversal(Node* root) {
    if(root == nullptr) return {};
    
    queue<Node*> q;
    q.push(root);
    vector<int> result;
    bool ltr = true;
	
    while(!q.empty()) {
        int s = q.size();
        
        for(int i = 0; i < s; ++i) {
            Node* current = q.front();
			q.pop();
			
			int index = ltr ? i : s-i-1;
			
			result[index] = current->data;
            
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        ltr = !ltr;
	}
	return result;
}