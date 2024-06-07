public:
    //Function to find the vertical order traversal of Binary Tree.
    void find(Node* root,int pos,int &l,int &r)
    {
        if(root==NULL)
        {
            return;
        }
        l=min(pos,l);
        r=max(pos,r);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        int l=0,r=0;
        find(root,0,l,r);
        l=abs(l);
        queue<Node*>q;
        queue<int>ind;
        vector<queue<int>>pos(r+1);
        vector<queue<int>>neg(l+1);
        vector<int>ans;
        q.push(root);
        ind.push(0);
        //int indl=0,indr=0;
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            int i=ind.front();
            ind.pop();
            if(i<0)
            {
                neg[abs(i)].push(temp->data);
                
            }
            if(i>=0)
            {
                pos[i].push(temp->data);
            }
            if(temp->left)
            {
                q.push(temp->left);
                ind.push(i-1);
            }
            if(temp->right)
            {
                q.push(temp->right);
                ind.push(i+1);
            }
        }
    
        for(int i=neg.size();i>=0;i--)
        {
           while(!neg[i].empty())
           {
               ans.push_back(neg[i].front());
               
               neg[i].pop();
           }
        }
        for(int i=0;i<=r;i++)
        {
           while(!pos[i].empty())
           {
               ans.push_back(pos[i].front());
               
               pos[i].pop();
           }
        }
        
        return ans;
    }
};