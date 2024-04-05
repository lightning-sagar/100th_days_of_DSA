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

Node* getmiddle(Node* head) {
    if(head == NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    // Insertion in linked list
    insertathead(head, tail, 50);
    insertathead(head, tail, 20);
    insertathead(head, tail, 30);
    insertathead(head, tail, 40);

    prints(head);
    cout << "\nThe middle node is: ";
    Node* middle = getmiddle(head);
    if(middle != NULL)
        cout << middle->data;
    else
        cout << "List is empty or has only one node.";
    return 0;
}
