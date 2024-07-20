class Solution {
  public:

    bool solve(struct Node* tree, int index) {

        if (tree == NULL) {
            return true;
        }

        if (tree->left == NULL && tree->right == NULL) {
            return true;
        }

        if (tree->left == NULL || tree->right == NULL) {
            return false;
        }

        if (tree->data < tree->left->data || tree->data < tree->right->data) {
            return false;
        }

        return solve(tree->left, 2 * index + 1) && solve(tree->right, 2 * index + 2);
    }
    bool isHeap(struct Node* tree) {
        // code here

        return solve(tree, 0);
 
    }
};