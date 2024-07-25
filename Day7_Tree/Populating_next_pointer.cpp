// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]

Node* connect(Node* root) {
    if(!root) return NULL;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if (node != nullptr) {
            node->next = q.front(); 
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        } else {
            if (!q.empty()) {
                q.push(nullptr); 
            }
        }
    }
    return root;
}