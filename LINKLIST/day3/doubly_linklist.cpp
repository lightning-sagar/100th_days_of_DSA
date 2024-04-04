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

void insertatposi(Node* &head,Node* &tail,int posi,int data){
    Node* newnode = new Node(data);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    Node* prev = head;
    int i = 1;
    while(i< posi-1 ){
        prev = prev->next;
        i++;
    } 
    Node* curr = prev->next;
    prev->next = newnode;
    newnode->next = curr;
    curr->prev = newnode;
}

void deletionathead(Node* &head){
    Node* temp = head;
    head = temp->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void deletionattail(Node* &tail){
    Node* temp = tail;
    Node* prev = tail->prev;
    prev->next = NULL;
    temp->prev = NULL;
    tail = prev;
    delete temp;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,50);
    insertathead(head,tail,20);
    insertathead(head,tail,30);
    insertathead(head,tail,40);
    insertattail(head,tail,100);

    insertatposi(head,tail,4,80);
    prints(head);
    cout<<"removing head \n";
    deletionathead(head);
     
    prints(head);
    cout<<"removing tail  \n";
    deletionattail(tail);
    deletionattail(tail);
    prints(head);
}