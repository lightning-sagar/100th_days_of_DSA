class Solution {
public:
    string solve(TreeNode* root, vector<TreeNode*>& v, unordered_map<string,int>& m){
        if(!root) return "#";
        string s = to_string(root->val) + "," + solve(root->left,v,m) + "," + solve(root->right,v,m);
        if(m[s] == 1) v.push_back(root);
        m[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return {};
        unordered_map<string,int> m;
        vector<TreeNode*> v;
        solve(root,v,m);
        return v;
    }
};