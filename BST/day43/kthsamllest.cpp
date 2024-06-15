int kthSmallest(TreeNode* root, int& k) {
    if (root == nullptr) {
        return -1;  
    }
    
    int leftResult = kthSmallest(root->left, k);
    
    if (leftResult != -1) {
        return leftResult;
    }
    
    // Check current node
    k--;
    if (k == 0) {
        return root->val; // Current node is the kth smallest
    }
    
    // Traverse right subtree to find kth smallest
    return kthSmallest(root->right, k);
}