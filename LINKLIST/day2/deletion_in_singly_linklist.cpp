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
int findlength(Node* head){
    int i =0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i;
}

void prints(Node* &head){
    int i = 0;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        i++;
    } 
    cout<<"\n";
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

void insertattail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    Node* newnode = new Node(data);
    tail->next = newnode;
    tail = newnode;
}

void insertatposition(Node *&head, Node *&tail,int posi, int data){
    if(head == NULL){
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    int i = 1;
    Node* prev = head;
    if(posi == 0){
        insertathead(head,tail,data);
        return;
    }
    int len = findlength(head);
    if(posi >= len){
        insertattail(head,tail,data);
        return;
    }

    while(i < posi-1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    Node* newnode = new Node(data);
    newnode->next = curr;
    prev->next = newnode;
}


//deletion

void deletionaatail(Node* &head,Node* &tail){
    int len = findlength(head);
    Node* prev = head;
    int i = 1;
    while( i < len-1 ){
        prev = prev->next;
        i++;
    } 
    Node* temp = prev->next;
    tail = prev; 
    tail->next = NULL;
    delete temp;
}

void deletionatposition(Node* &head,Node* &tail,int posi){
    Node* prev = head;
    int i = 1;
    while( i < posi-1 ){
        prev = prev->next;
        i++;
    } 
    Node* curr = prev->next;
    Node* temp = curr;
    prev->next = curr->next;
    delete temp;
}

void deletionaahead(Node* &head,Node* &tail){
    Node* temp = head;
    head = temp->next;
    temp->next = NULL;
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
    insertatposition(head,tail,10,80);
    prints(head);


    deletionaatail(head,tail);
    deletionaahead(head,tail);
    prints(head);

    deletionatposition(head,tail,2);
    
    prints(head);
}