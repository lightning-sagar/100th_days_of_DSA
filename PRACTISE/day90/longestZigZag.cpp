class Solution {
public:
    int maxLength = 0;

    void solve(TreeNode* node, bool isLeft, int length) {
        if (!node) return;
        maxLength = max(maxLength, length);
        
        if (isLeft) {
            solve(node->left, false, length + 1);   
            solve(node->right, true, 1);            
        } else {
            solve(node->right, true, length + 1);   
            solve(node->left, false, 1);            
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        solve(root->left, false, 1);  
        solve(root->right, true, 1);  
        return maxLength;
    }
};