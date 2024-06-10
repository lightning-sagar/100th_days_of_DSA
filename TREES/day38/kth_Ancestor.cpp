Node* solve(Node* root, int& k, int node) {
    if (root == NULL) return NULL;

    // If the current node is the target node
    if (root->data == node) return root;

    // Search in left and right subtrees
    Node* left = solve(root->left, k, node);
    Node* right = solve(root->right, k, node);

    // If the node was found in left subtree and not in right subtree
    if (left != NULL && right == NULL) {
        k--;
        // If k becomes 0, current node is the kth ancestor
        if (k == 0) {
            return root;
        }
        return left;
    }
    
    // If the node was found in right subtree and not in left subtree
    if (left == NULL && right != NULL) {
        k--;
        // If k becomes 0, current node is the kth ancestor
        if (k == 0) {
            return root;
        }
        return right;
    }

    // If the node is not found in either subtree
    return NULL;
}

int kthAncestor(Node *root, int k, int node) {
    Node* ans = solve(root, k, node);
    if (ans == NULL || ans->data == node) {
        return -1;
    } else {
        return ans->data;
    }
}