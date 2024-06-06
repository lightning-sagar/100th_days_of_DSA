pair<int,int> fastd(Node* root){
        if(root == NULL){
            return make_pair(0, 0);
        }
        pair<int,int> l = fastd(root->left);
        pair<int,int> r = fastd(root->right);
        int op1 = l.first;
        int op2 = r.first;
        int op3 = l.second + r.second + 1;
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(l.second, r.second) + 1;
        return ans;
    }

    int diameter(Node* root) {
        return fastd(root).first;
    }