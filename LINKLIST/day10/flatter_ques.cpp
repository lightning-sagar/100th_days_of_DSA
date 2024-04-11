void flatten(TreeNode* root) {
        while(root){  
            if(root->left){
                TreeNode *temp = root->right;
                TreeNode *temp2 = root->left;
                while (temp2&&temp2->right){
                    temp2 = temp2->right;
                }
                root->right = root->left;
                temp2->right = temp;
            }
            root->left = NULL;
            root=root->right;
        }
    }