#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void prints(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    } 
}

void insertathead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    Node* newnode = new Node(data);
    newnode->next = head;
    head = newnode;
}

int findlength(Node* head){
    int i =0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i;
}

Node* swapinpair(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* curr = head;
    head = curr->next;
    
    curr->next = swapinpair(head->next);
     head->next = curr;
    return head;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head, tail, 50);
    insertathead(head, tail, 20);
    insertathead(head, tail, 30);
    insertathead(head, tail, 40);
    insertathead(head, tail, 10);
    prints(head);
    cout<<"\n\n";
    head = swapinpair(head);
    prints(head);


}