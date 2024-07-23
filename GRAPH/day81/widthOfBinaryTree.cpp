/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long start = q.front().second;  
            unsigned long long end = q.back().second;  
            ans = max(ans, int(end - start + 1));   
            
            for (int i = 0; i < size; ++i) {
                auto it = q.front();
                q.pop();
                unsigned long long idx = it.second - start;  
                if (it.first->left) q.push({it.first->left, 2 * idx + 1});
                if (it.first->right) q.push({it.first->right, 2 * idx + 2});
            }
        }
        return ans;
    }
};
