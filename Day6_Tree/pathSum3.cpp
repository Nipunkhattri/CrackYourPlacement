int countPaths(TreeNode* node, int targetSum) {
    if (node == nullptr) return 0;
    int count = 0;
    if (node->val == targetSum) count++;
    count += countPaths(node->left, targetSum - node->val);
    count += countPaths(node->right, targetSum - node->val);
    return count;
}
int pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return 0;
    int pathsFromRoot = countPaths(root, targetSum);
    int pathsFromLeft = pathSum(root->left, targetSum);
    int pathsFromRight = pathSum(root->right, targetSum);
    return pathsFromRoot + pathsFromLeft + pathsFromRight;
}