pair<bool, int> fastd(Node* root) {
        if (root == NULL) {
            return make_pair(true, 0); // A null tree is balanced and its height is 0
        }
        pair<bool, int> l = fastd(root->left);
        pair<bool, int> r = fastd(root->right);
        bool op1 = l.first;
        bool op2 = r.first;
        bool op3 = abs(l.second - r.second) <= 1; // Correct condition for balance
        pair<bool, int> ans;
        ans.second = max(l.second, r.second) + 1;
        ans.first = op1 && op2 && op3; // Tree is balanced if both subtrees are balanced and the current node is balanced
        return ans;
    }

    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root) {
        return fastd(root).first;
    }