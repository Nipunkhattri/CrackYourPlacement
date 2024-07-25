// Input: root = [2,1,3]
// Output: true

bool solve(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
    if (node == nullptr) return true;
    if (minNode != nullptr && node->val <= minNode->val) return false;
    if (maxNode != nullptr && node->val >= maxNode->val) return false;
    return solve(node->left, minNode, node) && solve(node->right, node, maxNode);
}

bool isValidBST(TreeNode* root) {
    return solve(root, nullptr, nullptr);
}