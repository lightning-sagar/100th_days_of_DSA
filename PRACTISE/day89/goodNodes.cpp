class Solution {
public:
    int solve(int prev, TreeNode* root) {
        if (!root) return 0;
        
        int count = 0;
        if (root->val >= prev) {
            count = 1;
            prev = root->val;  
        }
        
        return count + solve(prev, root->left) + solve(prev, root->right);
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return solve(root->val, root);
    }
};