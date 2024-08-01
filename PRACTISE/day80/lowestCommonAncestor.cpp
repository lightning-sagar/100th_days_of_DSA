class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        root->left = lowestCommonAncestor(root->left,p,q);
        root->right = lowestCommonAncestor(root->right,p,q);
        if(root->val==p->val || root->val==q->val)
            return root;
        if(root->left && root->right)
            return root;
        return root->left==NULL ? root->right : root->left;
    }
};