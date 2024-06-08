vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,map<int,vector<int>>>node;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* temp=it.first;
            int x=it.second.first;
            int y=it.second.second;
            node[x][y].push_back(temp->data);
            if(temp->left)
            {
                q.push({temp->left,{x-1,y+1}});
            }
            if(temp->right)
            {
                q.push({temp->right,{x+1,y+1}});
            }
        }
        vector<int>ans;
        for(auto i:node)
        {
            for(auto j:i.second)
            {
                for(auto k:j.second)    
                {
                    ans.push_back(k);
                }   
            }
        }
        return ans;
    }