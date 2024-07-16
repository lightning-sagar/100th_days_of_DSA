class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int convertToSumTree(Node* node) {
    // Base case
        if (node == NULL)
            return 0;
        int leftSum = convertToSumTree(node->left);
        int rightSum = convertToSumTree(node->right);
        
        int oldValue = node->data;
        node->data = leftSum + rightSum;
        
        return node->data + oldValue;
    }

    void toSumTree(Node *node) {
        convertToSumTree(node);
    }
};