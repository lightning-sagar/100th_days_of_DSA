
void getSucc(Node* root,int key,Node*& pre,Node*& suc)
    {
        if(root==NULL)
            return;
        if(root->key==key)
        {
            if(root->left)
            {
                Node* temp=root->left;
                while(temp->right)
                    temp=temp->right;
                pre=temp;
            }
            if(root->right)
            {
                Node* temp=root->right;
                while(temp->left)
                    temp=temp->left;
                suc=temp;
            }
            return;
        }
        if(root->key>key)
        {
            suc=root;
            getSucc(root->left,key,pre,suc);
        }
        else
        {
            pre=root;
            getSucc(root->right,key,pre,suc);
        }
    }


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        getSucc(root,key,pre,suc);
        return ;

    }