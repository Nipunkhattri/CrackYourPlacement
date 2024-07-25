class Solution{
    public:
    struct Info {
        bool isBST;
        int size;
        int min;
        int max;
    
        Info(bool isBST, int size, int min, int max)
            : isBST(isBST), size(size), min(min), max(max) {}
    };

Info solve(Node* root, int& max_size) {
    if (root == nullptr) {
        return Info(true, 0, INT_MAX, INT_MIN); // An empty tree is a BST
    }
    
    Info leftInfo = solve(root->left, max_size);
    Info rightInfo = solve(root->right, max_size);
    
    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && root->data < rightInfo.min) {
        int size = leftInfo.size + rightInfo.size + 1;
        max_size = max(max_size, size);
        return Info(true, size, min(root->data, leftInfo.min), max(root->data, rightInfo.max));
    }
    
    return Info(false, 0, 0, 0);
}

int largestBst(Node *root) {
    int max_size = 0;
    solve(root, max_size);
    return max_size;
}
}