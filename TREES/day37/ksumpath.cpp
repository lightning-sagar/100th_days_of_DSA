 int ans=0;
   void solve(Node* root,int k,int sum)
   {
       if(root==NULL)
         return;
        sum+=root->data;
        if(sum==k)
         ans++;
        solve(root->left,k,sum);
        solve(root->right,k,sum);
   }
   void abc(Node* root,int k)
   {
       if(root==NULL)
         return;
       solve(root,k,0);
       abc(root->left,k);
       abc(root->right,k);
   }
   int sumK(Node *root,int k)
    {
        abc(root,k);
       return ans; 
    }