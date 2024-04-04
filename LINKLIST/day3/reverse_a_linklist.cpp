#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void prints(Node* &head){
    int i = 0;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        i++;
    } 
}

void insertathead(Node* &head,Node* &tail,int data){
    //check condition if head or tail is node..... if yes then...
    if(head == NULL){
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    Node* newnode = new Node(data);
    newnode->next = head;
    head = newnode;
}

Node* reverse(Node* &head, Node* &tail){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = head;
    while(curr != NULL){
        forward = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    //insertion in linklist
    insertathead(head,tail,50);
    insertathead(head,tail,20);
    insertathead(head,tail,30);
    insertathead(head,tail,40);

    prints(head);
    cout<<"\n";
    head = reverse(head,tail);
    prints(head);
}