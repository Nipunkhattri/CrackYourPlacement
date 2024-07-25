// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
    if (node == nullptr) return;
    if (parent != nullptr) {
        graph[node].push_back(parent);
        graph[parent].push_back(node);
    }
    buildGraph(node->left, node, graph);
    buildGraph(node->right, node, graph);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    buildGraph(root, nullptr, graph);

    for (auto it : graph) {
        cout << it.first->val << " ";
        for (auto i : it.second) {
            cout << i->val << " ";
        }
        cout << '\n';
    }
    unordered_set<TreeNode*> visited;
    queue<pair<TreeNode*,int>> q;
    q.push({target,0});
    visited.insert(target);
    vector<int> result;
    while(!q.empty()){
        TreeNode* cur_val = q.front().first;
        int dis = q.front().second;
        q.pop();
        if(dis == k){
            result.push_back(cur_val->val);
        }
        for(TreeNode* it : graph[cur_val]){
            if(visited.find(it) == visited.end()){
                q.push({it,dis+1});
                visited.insert(it);
            }
        }
    }
    return result;
}