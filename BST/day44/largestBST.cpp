public:
    class triplet{
        public:
        int mx;
        int mn;
        int n;
        triplet(int mx,int mn,int n)
        {
            this->mx=mx;
            this->mn=mn;
            this->n=n;
        }
    };
    // int ans=1;
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    triplet helper(Node* root)
    {
        if(root==NULL)
        return {INT_MIN,INT_MAX,0};
        triplet left=helper(root->left);
        triplet right=helper(root->right);
        if(root->data>left.mx && root->data<right.mn)
        {
            // ans=max(ans,1+left.n+right.n);
            return {max(root->data,right.mx),min(root->data,left.mn),1+right.n+left.n};
        }
        else
        {
            return {INT_MAX,INT_MIN,max(left.n,right.n)};
        }
    }
    int largestBst(Node *root)
    {
        return helper(root).n;
    }