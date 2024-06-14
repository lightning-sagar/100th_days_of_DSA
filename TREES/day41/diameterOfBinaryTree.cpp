int diameterOfBinaryTree(TreeNode* root) {
    //ittrate
    //cal nodes of left and right
    //max of left + right + 1
    int diameter = 0;
    if(root==NULL) return 0;
    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    diameter = max(diameter, left+right+1);
    return max(left, right) + 1;
}