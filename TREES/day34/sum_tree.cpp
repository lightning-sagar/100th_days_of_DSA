void f(Node *root,long int &sum)
{
    if(root==NULL)
    return;
    sum = sum + root->key;
    f(root->left,sum);
    f(root->right,sum);
}
long int sumBT(Node* root)
{
    long int sum=0;
    f(root , sum);
    return sum;
}