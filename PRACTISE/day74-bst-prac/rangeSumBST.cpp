class Solution {
public:

    int solve(TreeNode* root, int low, int high, int &sum){
        if(!root) return 0;
        if(root->val >=low && root->val <= high){
            sum += root->val;
        }
        solve(root->left,low,high,sum);
        solve(root->right,low,high,sum);
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int sum = 0;
        return solve(root,low,high,sum);
        // while(root){
        //     if(root->val >=low && root->val <= high){
        //         sum += root->val;
        //     }
        //     if(root->val<low) root = root->right;
        //     else root = root->left;
        // }
        // return sum;
    }
};