
// /**
//  * Traverses the binary tree and builds a map of parent-child relationships.
//  *
//  * @param root The root node of the binary tree.
//  * @param mp A map to store the parent-child relationships.
//  * @param target The target value to search for in the binary tree.
//  *
//  * @throws None.
//  */
 Node*tr;
    void PARENT(Node*root,map<Node*,Node*>&mp,int target){
        if(!root) return;
        PARENT(root->left,mp,target);
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;
        if(root->data==target) tr=root;
        PARENT(root->right,mp,target);
    }

    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>parent;
        unordered_map<Node*,bool>vis;
        PARENT(root,parent,target);
        int ans=0;
        queue<Node*>q;
        // cout<<tr->data<<endl;
       if(tr!=NULL) q.push(tr);
        vis[tr]=true;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node*curr=q.front();
                q.pop();
                if(curr->left&&!vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right&&!vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent.find(curr)!=parent.end()&&!vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }
            }
            ans++;
        }
        return ans-1;