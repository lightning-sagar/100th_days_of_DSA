void inorder(TreeNode* root, queue<TreeNode*>& q) {
    if(root == NULL) return;
    inorder(root->left, q);
    q.push(root);
    inorder(root->right, q);
}

TreeNode* increasingBST(TreeNode* root) {
    queue<TreeNode*> q;
    inorder(root, q);
    TreeNode* res = new TreeNode(0);
    TreeNode* temp = res;
    while(!q.empty()) {
        temp->right = new TreeNode(q.front()->val);
        temp = temp->right;
        q.pop();
    }
    return res->right;
}