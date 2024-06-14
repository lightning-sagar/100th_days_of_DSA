#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void takeinput(Node* root){
    int data;
    cin>>data;
    while(data != -1){
        root = new Node(data);
        cin>>data;
    }
}

Node* insertIntoBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(root->data > val){
        root->left = insertIntoBST(root->left, val);
    }
    else{
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root){   
    if(root == NULL){   
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }   
}

Node* findNode(Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        return root;
    }
    if(root->data > val){
        return findNode(root->left, val);   
    }
    else{
        return findNode(root->right, val);
    }
}

Node* findMax(Node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->right == NULL){
        return root;
    }
    return findMax(root->right);
}

Node* findmin(Node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL){
        return root;
    }
    return findmin(root->left);
}

Node* deleteNode(Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data > val){
        root->left = deleteNode(root->left, val);
    }
    else if(root->data < val){
        root->right = deleteNode(root->right, val);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findmin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){

}