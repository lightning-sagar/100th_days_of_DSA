class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //inorder successor is leftmost child of right subtree
         if(x->right){
             Node* temp = x->right;
             while(temp->left){
                 temp = temp->left;
             }
             return temp;
         }
         else{
             Node* temp = root;
             Node* prev = NULL;
             while(temp){
                 if(temp->data > x->data){
                     prev = temp;
                     temp = temp->left;
                 }
                 else{
                     temp = temp->right;
                 }
             }
             return prev;
         }
    }
};