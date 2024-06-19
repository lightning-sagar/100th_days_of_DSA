pair<bool,int> solve(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,__INT_MAX__);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;   
    }
    pair<bool,int> left = solve(root->left);
    pair<bool,int> right = solve(root->right);
    if(left.first && right.first && (root->data > left.second && root->data < right.second)){
        pair<bool,int> p = make_pair(true,max(left.second,right.second));
        return p;
    }
    pair<bool,int> p = make_pair(false,max(left.second,right.second));
    return p;
}