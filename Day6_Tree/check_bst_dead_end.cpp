// Input :   
//                8
//              /   \ 
//            5      9
//          /  \     
//         2    7 
//        /
//       1     
          
// Output : 
// Yes
// Explanation : 
// Node 1 is a Dead End in the given BST.

bool solve(Node* root,int min,int max){
    if(!root) return false;
    if(min == max) return true;
    return solve(root->left,min,root->data-1) || solve(root->right,root->data+1,max);
}
bool isDeadEnd(Node *root)
{
    return solve(root,1,INT_MAX);
}