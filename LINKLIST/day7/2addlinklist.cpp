
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
Node* addTwoNumbers(Node* l1, Node* l2) {
    if (l1 == nullptr && l2 == nullptr) return nullptr; // Check if both lists are empty
    
    int carry = 0;
    Node* resultHead = nullptr;
    Node* resultTail = nullptr;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }
        
        carry = sum / 10; // Calculate carry
        sum %= 10; // Calculate remainder
        
        Node* newNode = new Node(sum); // Create a new node with the calculated sum
        
        if (resultHead == nullptr) {
            resultHead = newNode;
            resultTail = newNode;
        } else {
            resultTail->next = newNode;
            resultTail = resultTail->next;
        }
    }

    return resultHead;
}
Node* removeElement(Node* &head, int data) {
        Node* temp = head;
    Node* del = NULL;

    // Handle the case where the head itself contains the data to be removed
    while (temp != NULL && temp->data == data) {
        del = temp;
        temp = temp->next;
        delete del;
    }

    // Update the head after removal
    head = temp;

    // Traverse the list and remove nodes with the specified data
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == data) {
            del = temp->next;
            temp->next = temp->next->next;
            delete del;
        } else {
            temp = temp->next;
        }
    }

    return head;
    }

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    //insertion in linklist
    insertathead(head,tail,50);
    insertathead(head,tail,20);
    insertathead(head,tail,30);
    insertathead(head,tail,40);

    head = removeElement(head,20);
    prints(head);

    // head = addTwoNumbers(head,tail);
    // prints(head);
}
