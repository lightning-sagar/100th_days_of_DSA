 void leftsolve(Node* root,vector<int>&ans)
   {
       if(root==NULL)
        return;
       if(root->left==NULL && root->right==NULL)
       {
           return;
       }
      ans.push_back(root->data);
      if(root->left!=NULL)
      leftsolve(root->left,ans);
      else
       leftsolve(root->right,ans);
   }
     void rightsolve(Node* root,vector<int>&ans1)
   {
       if(root==NULL)
        return;
       if(root->left==NULL && root->right==NULL)
       {
           return;
       }
       if(root->right!=NULL)
        rightsolve(root->right,ans1);
      else
      rightsolve(root->left,ans1);
      ans1.push_back(root->data);
   }
   void leafsolve(Node* root,vector<int>&ans)
   {
       if(root==NULL)
        return;
       if(root->left==NULL && root->right==NULL)
       {
           ans.push_back(root->data);
           return;
       }
       leafsolve(root->left,ans);
       leafsolve(root->right,ans);
       return;
   }
    vector <int> boundary(Node *root)
    {
        
        vector<int>ans,ans1;
        if (!(root->left == NULL && root->right == NULL)) 
        {
        ans.push_back(root->data);
        }
        Node* temp=root;
        if(root->left!=NULL)
         leftsolve(root->left,ans);
         leafsolve(temp,ans);
         if(root->right!=NULL)
        rightsolve(temp->right,ans);
        return ans;
    }