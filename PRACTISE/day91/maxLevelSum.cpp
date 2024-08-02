class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        std::queue<TreeNode*> q;
        q.push(root);

        int maxSum = root->val;
        int levelWithMaxSum = 1; 
        int currentLevel = 1;

        while (!q.empty()) {
            int n = q.size();
            int currentSum = 0;

            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                levelWithMaxSum = currentLevel;
            }

            ++currentLevel;
        }

        return levelWithMaxSum;
    }
};