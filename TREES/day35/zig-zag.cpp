vector<int> zigZagTraversal(Node* root) {
        queue<Node*> q;
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        q.push(root);
        bool ltor = true; // Missing semicolon fixed
        while(!q.empty()) {
            int size = q.size();
            vector<int> ans(size); // Initialize with correct size
            for(int i = 0; i < size; i++) {
                Node* fn = q.front();
                q.pop();
                int index = ltor ? i : size - i - 1;
                ans[index] = fn->data; // Correct assignment of node's data
                if(fn->left) q.push(fn->left);
                if(fn->right) q.push(fn->right);
            }
            result.insert(result.end(), ans.begin(), ans.end()); // Append to result
            ltor = !ltor;
        }
        return result; // Return the correct variable
    }