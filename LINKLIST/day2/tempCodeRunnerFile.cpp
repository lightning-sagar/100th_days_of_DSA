#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
         
        Node(){
            data = 0;
            next = NULL;
            prev = NULL;
        }
        Node(int n){
            data = n;
            next = NULL;
            prev = NULL;
        }
};

void prints(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insertathead(Node* &head,Node* &tail,int data){
    Node* newnode = new Node(data);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertattail(Node* &head,Node* &tail,int data){
   Node* newnode = new Node(data);
   if(head == NULL){
      head = newnode;
      tail = newnode;
      return;
   }
   tail->next = newnode;
   newnode->prev = tail;
   tail = newnode;
   tail->next = NULL;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,50);
    insertathead(head,tail,20);
    insertathead(head,tail,30);
    insertathead(head,tail,40);
    insertattail(head,tail,100);
    prints(head);
}