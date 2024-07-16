
void inorderSet(Node* root, unordered_set<int>& s) {
    if (!root) return;
    inorderSet(root->left, s);
    s.insert(root->data);
    inorderSet(root->right, s);
}

void inorderCount(Node* root, unordered_set<int>& s, int x, int& count) {
    if (!root) return;
    inorderCount(root->left, s, x, count);
    if (s.count(x - root->data)) count++;
    inorderCount(root->right, s, x, count);
}

int countPairs(Node* root1, Node* root2, int x) {
    int count = 0;
    unordered_set<int> s;
    inorderSet(root1, s);              
    inorderCount(root2, s, x, count);  
    return count;
}
