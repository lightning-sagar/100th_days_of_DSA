node buildTree(node* root){
    queue<node*>q;
    cin>>datal
    root = new node(datal);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cin>>datal;
        if(datal != -1){
            temp->left = new node(datal);
            q.push(temp->left);
        }
        cin>>datal;
        if(datal != -1){
            temp->right = new node(datal);
            q.push(temp->right);
        }
    }
    return root;
}