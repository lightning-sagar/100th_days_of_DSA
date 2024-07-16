class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node *root){
    if(root == NULL) {
 
        return make_pair(0, 0);
    }

     
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);
 
    int include = root->data + left.second + right.second;
    int exclude = max(left.first, left.second) + max(right.first, right.second);
    return make_pair(include, exclude);
}


int getMaxSum(Node *root) {
    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
}
};