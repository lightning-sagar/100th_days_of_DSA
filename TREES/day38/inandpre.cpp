int mapping(int in[], int n, map<int, queue<int> > &m){
        for(int i=0; i<n; i++){
            m[in[i]].push(i);
        }
    }
    Node* solve(int in[], int pre[], int &index, int instart, int inend, int n, map<int, queue<int> > &m){
        if(index>=n || instart>inend){
            return NULL;
        }
        int element = pre[index++];
        Node* root = new Node(element);
        int position = m[element].front();
        m[element].pop();
        root->left = solve(in, pre, index, instart, position-1, n, m);
        root->right = solve(in, pre, index, position+1, inend, n, m);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int index = 0;
        map<int, queue<int> > m;
        mapping(in, n, m);
        Node* root = solve(in, pre, index, 0, n-1, n, m);
        return root;
        // Code here
    }